/*******************************************************************************************
**
** Project: Obj Model Viewer
** File: glwidget.cpp
**
** Copyright (C) 2011 techvoid.
** All rights reserved.
** http://sourceforge.net/projects/objmodelviewer/
**
** This program is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either
** version 3 of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with this
** program. If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************************/

/*======================================== HEADERS =======================================*/

#include "glwidget.h"

#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>

#include <QtCore/QTime>

#include <QtCore/QDebug>

#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>


/*======================================== PUBLIC ========================================*/

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    disPos = 0;

    perspective = false;
    wireframe   = false;
    stats       = false;
    smooth      = false;
    model       = NULL;
    pmodel1     = NULL;

    fpsTime = new QTime;

    bgColor = QColor::fromRgb(0,0,0,0);
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::readFromFile(char *file)
{
    if (file != model) {
        model = file;
        pmodel1 = glmReadOBJ(model);
        glmUnitize(pmodel1);
        glmFacetNormals(pmodel1);
        printf("model loaded \"%s\"\n", model);
    }
    updateGL();
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

/*===================================== PUBLIC SLOTS =====================================*/

void GLWidget::setWireframe(bool value)
{
    wireframe = value;
    updateGL();
}

void GLWidget::setSmooth(bool value)
{
    smooth = value;
    updateGL();
}

void GLWidget::setStats(bool value)
{
    stats = value;
    updateGL();
}

void GLWidget::setPerspective(bool value)
{
    perspective = value;
    updateCamera();
    updateGL();
}

void GLWidget::setBgColor(QColor value)
{
    bgColor = value;
    updateGL();
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setDistance(int dis)
{
    if (dis != disPos) {
        disPos = dis;
        emit distanceChanged(dis);
    }
    updateCamera(); // update projection
    updateGL(); // calls glDraw() -> paintGL()
}

/*===================================== PRIVATE SLOTS ====================================*/

/*======================================= PROTECTED ======================================*/

void GLWidget::initializeGL()
{
    //qglClearColor(bgColor);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GLWidget::paintGL()
{
    qglClearColor(bgColor);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    frames++;
    elapsedTime = fpsTime->elapsed();

    if(elapsedTime - baseTime > 1000) {
        fps = frames * 1000.0/(elapsedTime-baseTime);
        baseTime = elapsedTime;
        frames = 0;
    }

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    if (wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1);
        glDisable(GL_LIGHTING);
        glDisable(GL_CULL_FACE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glEnable(GL_LIGHTING);
        glEnable(GL_CULL_FACE);
    }

    int numvertices(0), numtriangles(0), nummaterials(0),
        numtextures(0), numnormals(0), numgroups(0);

    bool isLoaded = (model != NULL) ? true : false;
    if (isLoaded) {
        if (smooth)
            glmDraw(pmodel1, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
        else
            glmDraw(pmodel1, GLM_FLAT | GLM_TEXTURE | GLM_MATERIAL);

        numvertices = pmodel1->numvertices;
        numtriangles = pmodel1->numtriangles;
        nummaterials = pmodel1->nummaterials;
        numtextures = pmodel1->numtextures;
        numnormals = pmodel1->numnormals;
        numgroups = pmodel1->numgroups;
    }

    if (stats) {
        renderText(20,20, isLoaded ? QString("Model is loaded") :
                   QString("Model is not loaded"), QFont("TypeWriter", 10, QFont::Bold));
        renderText(20,35,   QString("vertices: ")   + QString::number(numvertices));
        renderText(20,50,   QString("triangles: ")  + QString::number(numtriangles));
        renderText(20,65,   QString("materials: ")  + QString::number(nummaterials));
        renderText(20,80,   QString("textures: ")   + QString::number(numtextures));
        renderText(20,95,   QString("normals: ")    + QString::number(numnormals));
        renderText(20,110,  QString("groups: ")     + QString::number(numgroups));
        renderText(20,125,  QString("fps: ")        + QString::number(fps));
    }
}

void GLWidget::resizeGL(int width, int height)
{
    aspectRatio = (double)width/(double)height;
    glViewport(0, 0, width, height);

    updateCamera();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    if (event->orientation() == Qt::Vertical)
        setDistance(disPos + numSteps);

    event->accept();
}

/*======================================== PRIVATE =======================================*/

void GLWidget::updateCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(perspective)


        if (width() > height()) {
            glFrustum((-0.5 + disPos)*aspectRatio, (+0.5 - disPos)*aspectRatio,
                    -0.5 + disPos, +0.5 - disPos, 4.0, 15.0);
        } else {
            glFrustum(-0.5 + disPos, +0.5 - disPos, (-0.5 + disPos)/aspectRatio,
                    (+0.5 - disPos)/aspectRatio, 4.0, 15.0);
        }


    else


        if (width() > height()) {
            glOrtho((-0.5 + disPos)*aspectRatio, (+0.5 - disPos)*aspectRatio,
                    -0.5 + disPos, +0.5 - disPos, 4.0, 15.0);
        } else {
            glOrtho(-0.5 + disPos, +0.5 - disPos, (-0.5 + disPos)/aspectRatio,
                    (+0.5 - disPos)/aspectRatio, 4.0, 15.0);
        }



    glMatrixMode(GL_MODELVIEW);
}

/*========================================================================================*/
