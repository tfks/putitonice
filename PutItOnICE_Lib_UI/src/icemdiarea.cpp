
#include <QMdiArea>
#include <QPainter>

#include "headers/icemdiarea.h"

IceMdiArea::IceMdiArea(QWidget *parent) :
    QMdiArea(parent),
    m_backgroundDrawStyle(BackgroundDrawStyleFlags::TopLeft | BackgroundDrawStyleFlags::StretchedWithAspectRatio) //, m_pixmap("logo.jpg")
{

}

void IceMdiArea::setBackgroundImage(QString path)
{
    if (path == "") return;

    this->m_pixmapCurrent = this->m_pixmapOriginal = QPixmap(path);

    this->repaint();
}

void IceMdiArea::paintEvent(QPaintEvent *event)
{
    QMdiArea::paintEvent(event);

    if (!this->m_pixmapOriginal) return;

    QPainter painter(viewport());

    // Draw top left
    int x = 0;
    int y = 0;

    if (this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::BottomLeft))
    {
        y = this->height() - this->m_pixmapOriginal.height();
    }
    else if (this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::BottomRight))
    {
        // Draw in bottom right corner - Calculate the logo position - the bottom right corner of the mdi area.
        x = this->width() - this->m_pixmapOriginal.width();
        y = this->height() - this->m_pixmapOriginal.height();
    }
    else if (this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::TopLeft))
    {
        // default
    }
    else if (this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::TopRight))
    {
        y = this->width() - this->m_pixmapOriginal.width();
    }

    if (
        this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::Stretched) ||
        this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::StretchedWithAspectRatio)
       )
    {
        bool withAspectRatio = this->m_backgroundDrawStyle.testFlag(BackgroundDrawStyleFlags::StretchedWithAspectRatio);

        this->DrawWindowBackgroundStretched(withAspectRatio);
    }
    else
    {
        painter.drawPixmap(x, y, this->m_pixmapCurrent);
    }
}

void IceMdiArea::DrawWindowBackgroundStretched(bool withAspectRatio)
{
    float cw = this->width(), ch = this->height();
    float pw = this->m_pixmapOriginal.width(), ph = this->m_pixmapOriginal.height();

    if (withAspectRatio == true)
    {
        this->m_pixmapCurrent = this->m_pixmapOriginal.scaled(cw,
                                                              ch,
                                                              Qt::KeepAspectRatioByExpanding,
                                                              Qt::TransformationMode::FastTransformation);
    }
    else
    {
        if (
            (pw > cw && ph > ch && pw/cw > ph/ch) || // both width and high are bigger, ratio at height is bigger or
            (pw > cw && ph <= ch) ||                 // only the width is bigger or
            (pw < cw && ph < ch && cw/pw < ch/ph)    // both width and height is smaller, ratio at width is smaller
           )
        {
            this->m_pixmapCurrent = this->m_pixmapOriginal.scaledToWidth(cw, Qt::TransformationMode::FastTransformation);
        }
        else if (
            (pw > cw && ph > ch && pw/cw <= ph/ch) || // both width and high are bigger, ratio at width is bigger or
            (ph > ch && pw <= cw) ||                  // only the height is bigger or
            (pw < cw && ph < ch && cw/pw > ch/ph)     // both width and height is smaller, ratio at height is smaller
           )
        {
            this->m_pixmapCurrent = this->m_pixmapOriginal.scaledToHeight(ch, Qt::TransformationMode::FastTransformation);
        }
    }

    int x = (cw - this->m_pixmapCurrent.width()) / 2, y = (ch - this->m_pixmapCurrent.height()) / 2;

    QPainter painter(viewport());

    painter.drawPixmap(x, y, this->m_pixmapCurrent);
}
