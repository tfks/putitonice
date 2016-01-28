#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

//#include "headers/mainwindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    //void setMainWidget(QMainWindow *widget);

    void updatePosition(QRect taskBarGeometry);

private:
    Ui::MainMenu *ui;

    //QMainWindow *mainWidget;
};

#endif // MAINMENU_H
