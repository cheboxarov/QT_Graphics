#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    MyView(QGraphicsScene* scene, QWidget* parent);

public slots:
    void slotZoomIn();
    void slotZoomOut();
    void slotRotateLeft();
    void slotRotateRight();
};

#endif // MYVIEW_H
