#include "myview.h"

MyView::MyView(QGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent) {}

void MyView::slotZoomIn()
{
    scale(1.1, 1.1);
}

void MyView::slotZoomOut()
{
    scale(1 / 1.1, 1 / 1.1);
}

void MyView::slotRotateLeft()
{
    rotate(-5);
}

void MyView::slotRotateRight()
{
    rotate(5);
}
