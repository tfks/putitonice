#include <QtGui>

#include "headers/mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setGeometry(100, 100, 300, 500);

    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_PaintOnScreen);
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
    Q_UNUSED(taskBarGeometry);
    /*this->setGeometry(taskBarGeometry.left(),
                      taskBarGeometry.top() + this->height(),
                      taskBarGeometry.left() + this->width(),
                      taskBarGeometry.height());*/

}

void MainMenu::paintEvent(QPaintEvent *paintEvent)
{
    Q_UNUSED(paintEvent);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 0, 0, 127));

}

void MainMenu::on_pushButton_2_clicked()
{
    emit signal_applicationExit();    
    emit signal_closeAfterUserAction(this);
}

void MainMenu::on_pushButton_clicked()
{
    emit signal_showSettings();
    emit signal_closeAfterUserAction(this);
}
