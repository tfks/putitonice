#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "headers/taskbar.h"
#include "headers/icemdiarea.h"

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

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_actionExit_triggered();

private:
    void readSettings();
    void writeSettings();

    Ui::MainWindow *ui;

    TaskBar *taskBar;

    IceMdiArea *mdiArea;
    QSignalMapper *windowMapper;

    QMdiSubWindow *testSubWindow;

    QDialog *testWidget;
};

#endif // MAINWINDOW_H
