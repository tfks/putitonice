#include "headers/mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

MainMenu::~MainMenu()
{
    //delete this->mainWidget;

    delete ui;
}
/*
void MainMenu::setMainWidget(QMainWindow *widget)
{
    if (widget == NULL) return;

    this->mainWidget = widget;
}
*/

void MainMenu::updatePosition(QRect taskBarGeometry)
{
    /*this->setGeometry(taskBarGeometry.left(),
                      taskBarGeometry.top() + this->height(),
                      taskBarGeometry.left() + this->width(),
                      taskBarGeometry.height());*/

}

void MainMenu::on_pushButton_2_clicked()
{
    emit signal_applicationExit();
}

void MainMenu::on_pushButton_clicked()
{
    emit signal_showSettings();
}
