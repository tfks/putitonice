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

    this->mainMenuButton->setGeometry(0, 0, 48, 48);
    this->mainMenuButton->setCheckable(true);

    this->mainMenuButton->setStyleSheet("QPushButton { \
                                            background-image: url(\":/mainwindow/mainmenubutton_1\"); \
                                            border: none; \
                                         } \
                                         QPushButton:checked, \
                                            QPushButton:hover:checked { \
                                            background-image: url(\":/mainwindow/mainmenubutton_1_p\"); \
                                            border: none; \
                                         } \
                                         QPushButton:hover { \
                                            background-image: url(\":/mainwindow/mainmenubutton_1_h\"); \
                                            border: none; \
                                         }");

    this->connect(this->mainMenuButton, SIGNAL(clicked(bool)),
                  this, SLOT(slot_mainMenuButtonClicked(bool)));

    //this->connect(this->mainMenuButton, SIGNAL(triggered(bool)),
      //            this, SLOT(slot_mainMenuButtonClicked(bool)));

    this->UpdateGeometry(parent);
}

TaskBar::~TaskBar()
{
    //delete this->mainWidget;
    delete this->mainMenuButton;
}

void TaskBar::resizeEvent(QResizeEvent* event)
{
    TaskBar::resizeEvent(event);


}

QRect TaskBar::getGeometry()
{
    return this->geometry();
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

void TaskBar::setMainWidget(QMainWindow *widget)
{
    if (widget == NULL) return;

    this->mainWidget = widget;
}

void TaskBar::slot_mainMenuButtonClicked(bool checkedState)
{
    //bool checkedState = this->mainMenuButton->isChecked();

    emit signal_mainMenuButtonHasBeenClicked(checkedState);
}
