#ifndef TASKBAR_H
#define TASKBAR_H

#include <QWidget>
#include <QPushButton>

class TaskBar : public QWidget
{
    Q_OBJECT
public:
    explicit TaskBar(QWidget *parent = 0);
    ~TaskBar();

    void UpdateGeometry(int x, int y, int w, int h);
    void UpdateGeometry(QWidget *widget);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent* event);

private:
    QWidget *parentWidget;
    QPushButton *mainMenuButton;
};

#endif // TASKBAR_H
