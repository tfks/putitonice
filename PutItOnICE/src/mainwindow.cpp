
#include <QtWidgets>
#include <QMdiArea>
#include <QCloseEvent>
#include <QSettings>

#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/icemdisubwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mdiArea = new IceMdiArea(this);

    QString homeLocation = QStandardPaths::locate(QStandardPaths::HomeLocation, QString(), QStandardPaths::LocateDirectory);
    QString path = homeLocation + ".kde/share/wallpapers/120175-Wait-for-it.jpg";

    this->mdiArea->setBackgroundImage(path);

    //mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //mdiArea->setStyleSheet("padding-bottom: 48px;");

    QMainWindow::setCentralWidget(mdiArea);

    //connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(updateMenus()));
    this->windowMapper = new QSignalMapper(this);

    //connect(windowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindow(QWidget*)));

    this->testWidget = new QDialog();
    testWidget->setWindowFlags(Qt::SubWindow);
    testWidget->setSizeGripEnabled(true);

    QVBoxLayout* l = new QVBoxLayout;

    this->testWidget->setLayout(l);

    QPushButton* b = new QPushButton("hello");

    b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    l->addWidget(b);


    this->testWidget->show();



    IceMdiSubWindow *testSubWindow = new IceMdiSubWindow(this->mdiArea);
    //testSubWindow->setFixedSize(200,100);
    testSubWindow->setGeometry(10, 10, 400, 400);
    testSubWindow->setWidget(this->testWidget);
    testSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    testSubWindow->setOption(QMdiSubWindow::RubberBandMove);
    testSubWindow->setOption(QMdiSubWindow::RubberBandResize);
    testSubWindow->setOption(QMdiSubWindow::AllowOutsideAreaHorizontally);
    testSubWindow->setOption(QMdiSubWindow::AllowOutsideAreaVertically);
    //testSubWindow->setWindowFlags(Qt::SubWindow);
    //testSubWindow->setSizePolicy(QSizePolicy::Expanding);

    mdiArea->addSubWindow(testSubWindow);

    this->taskBar = new TaskBar(mdiArea);

    this->mainMenu = new MainMenu(mdiArea);
    //this->mainMenu->setMainWidget(this);
    //this->mainMenu->setSizeGripEnabled(true);

    this->mainMenuSubWindow = new IceMdiSubWindow(this->mdiArea);

    this->mainMenuSubWindow->setGeometry(100, 100, 300, 500);
    this->mainMenuSubWindow->setWidget(this->mainMenu);
    this->mainMenuSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    this->mainMenuSubWindow->setOption(QMdiSubWindow::RubberBandMove);
    this->mainMenuSubWindow->setOption(QMdiSubWindow::RubberBandResize);
    this->mainMenuSubWindow->setOption(QMdiSubWindow::AllowOutsideAreaHorizontally);
    this->mainMenuSubWindow->setOption(QMdiSubWindow::AllowOutsideAreaVertically);


    this->mdiArea->addSubWindow(this->mainMenuSubWindow);
    this->mainMenuSubWindow->setHidden(true);

    this->connect(this->taskBar, SIGNAL(signal_mainMenuButtonHasBeenClicked(bool)),
                  this, SLOT(slot_on_mainMenuButtonHasBeenClicked(bool)));

    this->readSettings();

    this->setUnifiedTitleAndToolBarOnMac(true);

}

MainWindow::~MainWindow()
{

    delete this->windowMapper;

    //delete this->mainMenu;

    //delete this->mainMenuSubWindow;

    delete this->taskBar;

    delete this->mdiArea;

    delete ui;
}

void MainWindow::readSettings()
{
    QSettings settings("PutItOnICE", "Put It On ICE");

    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();

    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings("PutItOnICE", "Put It On ICE");

    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void MainWindow::slot_on_actionExit_triggered()
{
    this->close();
}

void MainWindow::slot_on_mainMenuButtonHasBeenClicked(bool checkedState)
{
    if (checkedState == true) {
        this->mainMenuSubWindow->show();
    }
    else {
        this->mainMenuSubWindow->hide();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mdiArea->closeAllSubWindows();

    if (mdiArea->currentSubWindow())
    {
        event->ignore();
    } else {
        this->writeSettings();
        event->accept();
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    if (this->taskBar)
    {
        this->taskBar->UpdateGeometry(this);

        //if (this->mainMenu) this->mainMenu->updatePosition(this->taskBar->getGeometry());
    }
}
