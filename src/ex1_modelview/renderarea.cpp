#include "renderarea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor color(100, 120, 110);
    painter.setBrush(color);
    
    painter.drawRect(0, 0, width()-1, height()-1);
}
