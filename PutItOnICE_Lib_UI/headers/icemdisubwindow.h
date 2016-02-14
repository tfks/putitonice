#ifndef ICEMDISUBWINDOW_H
#define ICEMDISUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>

class IceMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    IceMdiSubWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~IceMdiSubWindow();

    void setWidget(QWidget *widget);

protected:
    void hideEvent(QHideEvent *event) Q_DECL_OVERRIDE;
    void childEvent(QChildEvent *childEvent) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *paintEvent) Q_DECL_OVERRIDE;

private:
    void widgetAdded();
};

#endif // ICEMDISUBWINDOW_H
