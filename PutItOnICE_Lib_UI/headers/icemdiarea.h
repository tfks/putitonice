#ifndef ICEMDIAREA_H
#define ICEMDIAREA_H

#include <QMdiArea>
#include <QPaintEvent>

#include "headers/backgrounddrawstyleflags.h"

class IceMdiArea : public QMdiArea
{
    Q_OBJECT
    Q_ENUM(BackgroundDrawStyleFlags)

public:
    explicit IceMdiArea(QWidget *parent = 0);
    void setBackgroundImage(QString path);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void DrawWindowBackgroundStretched(bool withAspectRatio = false);

    // Store the logo image.
    QPixmap m_pixmapOriginal;
    QPixmap m_pixmapCurrent;

    BackgroundDrawStyleFlags::BackgroundDrawStyles m_backgroundDrawStyle;
};

#endif // ICEMDIAREA_H
