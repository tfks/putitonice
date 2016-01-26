#include "headers/icemdisubwindow.h"

IceMdiSubWindow::IceMdiSubWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent)
{
    QMdiSubWindow::setWindowFlags(flags);
}

IceMdiSubWindow::~IceMdiSubWindow()
{

}

void IceMdiSubWindow::hideEvent(QHideEvent *event)
{
    QMdiSubWindow::hideEvent(event);

    this->hide();
}
