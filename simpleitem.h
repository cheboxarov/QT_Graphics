#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H

#include <QGraphicsItem>

class SimpleItem : public QGraphicsItem
{
private:
    enum {nPenWidth = 3};
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter* p_painter, const QStyleOptionGraphicsItem*, QWidget*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* ev) ;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* ev) ;
};

#endif // SIMPLEITEM_H
