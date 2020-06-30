/*******************************************************************************************
**
** Project: Obj Model Viewer
** File: window.h
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

#ifndef WINDOW_H
#define WINDOW_H

#include "generated/window_ui.h"

/*======================================== CLASSES =======================================*/

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

class GLWidget;

class Window : public QMainWindow
{
        Q_OBJECT

    public:
        Window(QWidget *parent = 0);
        static Window *Instance();
        static void Drop();

    public slots:
        bool openFile(const QString &Path = QString());

    private slots:
        void IsSliders();
        void IsSmooth();
        void IsWireframe();
        void IsStats();
        void IsPerspective();
        void PickColor();
        void SetSliders(bool value);
        void About();

    protected:
        void keyPressEvent(QKeyEvent *event);
        void dragEnterEvent(QDragEnterEvent *event);
        void dragMoveEvent(QDragMoveEvent *event);
        void dragLeaveEvent(QDragLeaveEvent *event);
        void dropEvent(QDropEvent *event);

    private:
        Window(const Window &);
        Window &operator=(const Window &);
        static Window *instance;
        Ui_windowClass MainWindow;

        QAction *openAct;
        QAction *OptionsAct;
        QAction *AboutAct;
        QAction *exitAct;

        QSlider *createSlider();
        QSlider *createZoomSlider();

        GLWidget *glWidget;
        QSlider  *xSlider;
        QSlider  *ySlider;
        QSlider  *zSlider;
        QSlider  *disSlider;
};

#endif // WINDOW_H

/*========================================================================================*/
