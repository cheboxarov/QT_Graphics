
#include "simpleitem.h"
#include "QApplication"
#include <QPainter>

void SimpleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* ev)
{
    QApplication::restoreOverrideCursor();
    QGraphicsItem::mouseReleaseEvent(ev);
}

void SimpleItem::mousePressEvent(QGraphicsSceneMouseEvent* ev)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    QGraphicsItem::mousePressEvent(ev);
}

void SimpleItem::paint(QPainter* p_painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    p_painter->save();
    p_painter->setPen(QPen(Qt::black, nPenWidth));
    p_painter->drawEllipse(-10,-10,30,30);
    p_painter->restore();
}

QRectF SimpleItem::boundingRect() const
{
    QPointF rect(-10 - nPenWidth, -10 - nPenWidth);
    QSizeF size(20+nPenWidth, 20+nPenWidth);
    return QRectF(rect, size);
}
