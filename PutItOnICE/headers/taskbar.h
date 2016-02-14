#ifndef TASKBAR_H
#define TASKBAR_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

class TaskBar : public QWidget
{
    Q_OBJECT
public:
    explicit TaskBar(QWidget *parent = 0);
    ~TaskBar();

    void UpdateGeometry(int x, int y, int w, int h);
    void UpdateGeometry(QWidget *widget);

    QRect getGeometry();
    void updatePosition(QRect taskBarGeometry);
    void setMainMenuButtonClickedState(bool checkedState);

signals:
    void signal_mainMenuButtonHasBeenClicked(bool checkedState);

private slots:
    void slot_mainMenuButtonClicked(bool checkedState);

protected:
    void resizeEvent(QResizeEvent* event);

private:
    QWidget *parentWidget;
    QPushButton *mainMenuButton;

    QMainWindow *mainWidget;

    void setMainWidget(QMainWindow *widget);
};

#endif // TASKBAR_H
