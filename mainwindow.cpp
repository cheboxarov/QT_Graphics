#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(QRect(-100,-100, 300, 300));
    view = new MyView(scene, this);
    view->resize(this->size());
    QGraphicsRectItem* item_rect = scene->addRect(QRect(-30, -30, 120, 80), QPen(Qt::black), QBrush(Qt::gray));
    item_rect->setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsLineItem* item_line = scene->addLine(QLine(0,0, 60, 60), QPen(Qt::black));
    item_line->setFlag(QGraphicsItem::ItemIsMovable);
    SimpleItem* my_item = new SimpleItem;
    scene->addItem(my_item);
    my_item->setPos(0,0);
    my_item->setFlag(QGraphicsItem::ItemIsMovable);

    QPushButton* btn_zoom_in = new QPushButton("Zoom in");
    QPushButton* btn_zoom_out = new QPushButton("Zoom out");
    QPushButton* btn_rotate_left = new QPushButton("Rotate left");
    QPushButton* btn_rotate_right = new QPushButton("Rotate right");

    QObject::connect(btn_zoom_in, &QPushButton::clicked, view, &MyView::slotZoomIn);
    QObject::connect(btn_zoom_out, &QPushButton::clicked, view, &MyView::slotZoomOut);
    QObject::connect(btn_rotate_left, &QPushButton::clicked, view, &MyView::slotRotateLeft);
    QObject::connect(btn_rotate_right, &QPushButton::clicked, view, &MyView::slotRotateRight);

    ui->centralwidget->setLayout(new QVBoxLayout);
    ui->centralwidget->layout()->addWidget(view);
    ui->centralwidget->layout()->addWidget(btn_zoom_in);
    ui->centralwidget->layout()->addWidget(btn_zoom_out);
    ui->centralwidget->layout()->addWidget(btn_rotate_left);
    ui->centralwidget->layout()->addWidget(btn_rotate_right);
}

MainWindow::~MainWindow()
{
    delete ui;
}
