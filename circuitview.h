#ifndef CIRCUITVIEW_H
#define CIRCUITVIEW_H

#include <QFrame>

QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QGraphicsScene)

class CircuitView : public QFrame
{
    Q_OBJECT
public:
    CircuitView(QWidget *parent = 0);
private:
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
};

#endif // CIRCUITVIEW_H
