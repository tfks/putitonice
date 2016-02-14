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

protected:
        virtual void paintEvent(QPaintEvent *paintEvent);

signals:
    void signal_closeAfterUserAction(QWidget *widget);
    void signal_showSettings();
    void signal_applicationExit();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;

    //QMainWindow *mainWidget;
};

#endif // MAINMENU_H
