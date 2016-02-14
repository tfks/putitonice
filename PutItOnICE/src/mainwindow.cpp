
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
    //QString path = homeLocation + ".local/share/wallpapers/98258-clear_skies1920x1200.jpg";

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


    this->addWidgetToMdiArea(testWidget);

    IceMdiSubWindow *testSubWindow = this->getSubWindowByWidget(testWidget);

    if (testSubWindow)
    {
        //testSubWindow->setFixedSize(200,100);
        testSubWindow->setGeometry(10, 10, 400, 400);

        testSubWindow->setWindowFlags(Qt::Window);
        //testSubWindow->setSizePolicy(QSizePolicy::Expanding);
        testSubWindow->show();
    }

    this->taskBar = new TaskBar(mdiArea);

    this->connect(this->taskBar, SIGNAL(signal_mainMenuButtonHasBeenClicked(bool)),
                  this, SLOT(slot_on_mainMenuButtonHasBeenClicked(bool)));

    this->readSettings();

    this->setUnifiedTitleAndToolBarOnMac(true);

}

MainWindow::~MainWindow()
{

    delete this->windowMapper;

    delete this->taskBar;

    delete this->mdiArea;

    delete ui;
}

void MainWindow::addWidgetToMdiArea(QWidget *widget, bool showInitially)
{
    if (!widget) return;

    widget->setWindowFlags(Qt::Window);

    IceMdiSubWindow *subWindowtoAdd = new IceMdiSubWindow(this->mdiArea);

    //subWindowtoAdd->setFixedSize(200,100);
    //testSubWindow->setAttribute(Qt::WA_SetWindowIcon, );
    subWindowtoAdd->setGeometry(widget->geometry());

    subWindowtoAdd->setWidget(widget);

    subWindowtoAdd->setAttribute(Qt::WA_DeleteOnClose);
    subWindowtoAdd->setOption(QMdiSubWindow::RubberBandMove);
    subWindowtoAdd->setOption(QMdiSubWindow::RubberBandResize);
    subWindowtoAdd->setOption(QMdiSubWindow::AllowOutsideAreaHorizontally);
    subWindowtoAdd->setOption(QMdiSubWindow::AllowOutsideAreaVertically);
    subWindowtoAdd->setWindowFlags(Qt::SubWindow);
    //subWindowtoAdd->setSizePolicy(QSizePolicy::Expanding);

    this->mdiArea->addSubWindow(subWindowtoAdd);

    if (showInitially == true) {
        subWindowtoAdd->show();
    }
}

IceMdiSubWindow *MainWindow::getSubWindowByWidget(QWidget *widget)
{
    if (!widget) return NULL;

    return qobject_cast<IceMdiSubWindow*>(widget->parentWidget());
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

void MainWindow::slot_on_showSettings_triggered()
{
    SettingsDialog *settingsDialog = new SettingsDialog(this);

    this->addWidgetToMdiArea(settingsDialog, true);
}

void MainWindow::slot_on_applicationExit_triggered()
{
    this->close();
}

void MainWindow::slot_on_mainMenuButtonHasBeenClicked(bool checkedState)
{
    if (checkedState == true) {
        this->mainMenu = new MainMenu(mdiArea);

        this->addWidgetToMdiArea(this->mainMenu, true);

        QMdiSubWindow *mainMenuSubWindow = this->getSubWindowByWidget(this->mainMenu);

        mainMenuSubWindow->setObjectName("MainMenu");

        mainMenuSubWindow->setGeometry(this->mainMenu->geometry());

        this->connect(this->mainMenu, SIGNAL(signal_showSettings()),
                      this, SLOT(slot_on_showSettings_triggered()));

        this->connect(this->mainMenu, SIGNAL(signal_applicationExit()),
                      this, SLOT(slot_on_applicationExit_triggered()));

        this->connect(this->mainMenu, SIGNAL(signal_closeAfterUserAction(QWidget*)),
                      this, SLOT(slot_on_closeAfterUserAction(QWidget*)));

        mainMenuSubWindow->setGeometry(0,
                                       this->height() - (mainMenuSubWindow->height() + this->taskBar->height()),
                                       mainMenuSubWindow->width(),
                                       mainMenuSubWindow->height());

        mainMenuSubWindow->setStyleSheet("MainMenu { background-color: #345b94; }");
        mainMenuSubWindow->setBackgroundRole(QPalette::Window);

        mainMenuSubWindow->setWindowFlags(Qt::FramelessWindowHint);

        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();

        opacityEffect->setOpacity(0.9);

        mainMenuSubWindow->setAutoFillBackground(true);
        mainMenuSubWindow->setGraphicsEffect(opacityEffect);

        //mainMenuSubWindow->show();


    }
    else {
        QMdiSubWindow *mainMenuSubWindow = this->getSubWindowByWidget(this->mainMenu);

        if (!mainMenuSubWindow) return;

        this->mdiArea->removeSubWindow(mainMenuSubWindow);
        mainMenuSubWindow->close();
    }
}

void MainWindow::slot_on_closeAfterUserAction(QWidget *widget)
{
    if (widget) {
        IceMdiSubWindow *subWindow = this->getSubWindowByWidget(widget);

        if (subWindow) {
            subWindow->close();

            this->taskBar->setMainMenuButtonClickedState(false);
        }
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
