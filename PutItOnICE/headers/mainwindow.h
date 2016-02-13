#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "headers/taskbar.h"
#include "headers/mainmenu.h"
#include "headers/settingsdialog.h"
#include "headers/icemdiarea.h"
#include "headers/icemdisubwindow.h"

class MdiChild;
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addWidget(QWidget *widget, bool showInitially = false);

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent* event);

private slots:
    void slot_on_actionExit_triggered();

public slots:
    void slot_on_showSettings_triggered();
    void slot_on_applicationExit_triggered();
    void slot_on_mainMenuButtonHasBeenClicked(bool checkedState);

private:
    IceMdiSubWindow *getSubWindowByWidget(QWidget *widget);
    void readSettings();
    void writeSettings();

    Ui::MainWindow *ui;

    TaskBar *taskBar;
    MainMenu *mainMenu;

    //SettingsDialog * settingsDialog;

    //IceMdiSubWindow *mainMenuSubWindow;

    IceMdiArea *mdiArea;
    QSignalMapper *windowMapper;

    QMdiSubWindow *testSubWindow;

    //QList<QMdiSubWindow> subWindowList;

    QDialog *testWidget;
};

#endif // MAINWINDOW_H
