/*******************************************************************************************
**
** Project: Obj Model Viewer
** File: glwidget.h
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

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include "glm.h"

/*======================================== CLASSES =======================================*/

QT_BEGIN_NAMESPACE
class QTime;
QT_END_NAMESPACE

class GLWidget : public QGLWidget
{
        Q_OBJECT

    public:
        GLWidget(QWidget *parent = 0);

        QSize sizeHint() const;
        QSize minimumSizeHint() const;
        void readFromFile(char *file);

    public slots:
        void setWireframe(bool value);
        void setSmooth(bool value);
        void setStats(bool value);
        void setPerspective(bool value);
        void setBgColor(QColor value);
        void setXRotation(int angle);
        void setYRotation(int angle);
        void setZRotation(int angle);
        void setDistance(int dis);

    signals:
        void xRotationChanged(int angle);
        void yRotationChanged(int angle);
        void zRotationChanged(int angle);

        void distanceChanged(int dis);

    protected:
        void initializeGL();
        void paintGL();
        void resizeGL(int width, int height);
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void wheelEvent(QWheelEvent *event);

    private:
        int xRot;
        int yRot;
        int zRot;
        int disPos;
        int windowWidth;
        int windowHeight;
        double aspectRatio;
        QPoint lastPos;

        void updateCamera();

        QColor bgColor;

        QTime *fpsTime;
        int fps, frames, elapsedTime, baseTime;

        bool perspective;
        bool wireframe;
        bool stats;
        bool smooth;
        char *model;
        GLMmodel *pmodel1;
};

#endif // GLWIDGET_H

/*========================================================================================*/
