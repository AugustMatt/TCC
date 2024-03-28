#include "circuitview.h"
#include "circuititem.h"
#include <QtGui>

CircuitView::CircuitView(QWidget *parent)
    : QFrame(parent)
{
    CircuitItem *item = new CircuitItem(QString("AND"));
    graphicsView = new QGraphicsView(this);
    graphicsView->setRenderHint(QPainter::Antialiasing, false);
    graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    scene = new QGraphicsScene;
    item->setPos(30,30);
    scene->addItem(item);
    graphicsView->setScene(scene);
    graphicsView->show();
}
