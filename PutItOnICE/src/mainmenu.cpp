#include "headers/mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::SubWindow);


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
    this->setGeometry(taskBarGeometry.left(),
                      taskBarGeometry.top() + this->height(),
                      taskBarGeometry.left() + this->width(),
                      taskBarGeometry.height());
}
