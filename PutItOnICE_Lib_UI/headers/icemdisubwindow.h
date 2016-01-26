#ifndef ICEMDISUBWINDOW_H
#define ICEMDISUBWINDOW_H

#include <QMdiSubWindow>

class IceMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    IceMdiSubWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~IceMdiSubWindow();

protected:
    void hideEvent(QHideEvent *event);
};

#endif // ICEMDISUBWINDOW_H
