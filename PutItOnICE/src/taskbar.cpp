#include <QWidget>
#include <QMainWindow>
#include <QRect>

#include "headers/taskbar.h"

TaskBar::TaskBar(QWidget *parent) : QWidget(parent)
{
    this->parentWidget = parent;

    this->setWindowFlags(Qt::Window);
    this->setGeometry(0, 0, 100, 48);
    //this->show();

    this->mainMenuButton = new QPushButton(parent);

    this->mainMenuButton->setGeometry(0, 0, 100, 48);
    this->mainMenuButton->setCheckable(true);

    this->mainMenuButton->setStyleSheet("QPushButton { \
                                            background-image: url(\":/mainwindow/mainmenubutton\"); \
                                            border: none; \
                                         } \
                                         QPushButton:checked, \
                                            QPushButton:hover:checked { \
                                            background-image: url(\":/mainwindow/mainmenubutton_p\"); \
                                            border: none; \
                                         } \
                                         QPushButton:hover { \
                                            background-image: url(\":/mainwindow/mainmenubutton_h\"); \
                                            border: none; \
                                         }");

    //this->setMainMenuButtonPosition(this->parentWidget);
    this->UpdateGeometry(parent);
}

TaskBar::~TaskBar()
{
    delete this->mainMenuButton;
}

void TaskBar::resizeEvent(QResizeEvent* event)
{
    TaskBar::resizeEvent(event);


}

void TaskBar::UpdateGeometry(QWidget *widget)
{
    this->UpdateGeometry(widget->geometry().left(),
                         widget->geometry().top(),
                         widget->geometry().width(),
                         widget->geometry().height());
}

void TaskBar::UpdateGeometry(int x, int y, int w, int h)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(w);

    QRect buttonRect = this->mainMenuButton->geometry();

    this->mainMenuButton->setGeometry(0,
                                      h - buttonRect.height(),
                                      buttonRect.width(),
                                      buttonRect.height());
}
