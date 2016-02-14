#include <QtGui>
#include <QChildEvent>

#include "headers/icemdisubwindow.h"

IceMdiSubWindow::IceMdiSubWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent)
{
    QMdiSubWindow::setWindowFlags(flags);
}

IceMdiSubWindow::~IceMdiSubWindow()
{

}

void IceMdiSubWindow::setWidget(QWidget *widget)
{
    QMdiSubWindow::setWidget(widget);

    if (widget) {
        this->widgetAdded();
    }


}

void IceMdiSubWindow::hideEvent(QHideEvent *event)
{
    QMdiSubWindow::hideEvent(event);

    this->hide();
}

void IceMdiSubWindow::childEvent(QChildEvent *childEvent)
{
    QMdiSubWindow::childEvent(childEvent);

    if (childEvent->added())
    {

    }
}

void IceMdiSubWindow::paintEvent(QPaintEvent *paintEvent)
{
    //Q_UNUSED(paintEvent);
    QMdiSubWindow::paintEvent(paintEvent);

    /*QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 0, 0, 127));*/
}

void IceMdiSubWindow::widgetAdded()
{
    QWidget *childWidget = this->widget();

    if (childWidget) {
        this->setAttribute(Qt::WA_DeleteOnClose, childWidget->testAttribute(Qt::WA_DeleteOnClose));
        this->setAttribute(Qt::WA_TranslucentBackground, childWidget->testAttribute(Qt::WA_TranslucentBackground));
        this->setAttribute(Qt::WA_PaintOnScreen, childWidget->testAttribute(Qt::WA_PaintOnScreen));

        this->repaint();
    }
}
