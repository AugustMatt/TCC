#ifndef CONECTOR_H
#define CONECTOR_H

#include <QColor> // Inclui o cabeçalho para cores do Qt
#include <QGraphicsItem> // Inclui o cabeçalho para itens gráficos do Qt
#include <QGraphicsLineItem> // Inclui o cabeçalho para itens de linha gráfica do Qt
#include "circuititem.h" // Inclui o cabeçalho da classe CircuitItem

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem; // Declaração antecipada da classe QGraphicsPolygonItem
class QGraphicsLineItem; // Declaração antecipada da classe QGraphicsLineItem
class QGraphicsScene; // Declaração antecipada da classe QGraphicsScene
class QRectF; // Declaração antecipada da classe QRectF
class QGraphicsSceneMouseEvent; // Declaração antecipada da classe QGraphicsSceneMouseEvent
class QPainterPath; // Declaração antecipada da classe QPainterPath
QT_END_NAMESPACE

// Declaração da classe Connector, que herda de QGraphicsLineItem
class Connector : public QGraphicsLineItem
{
public:
    Connector(CircuitItem *_src, CircuitItem *_dst, // Construtor que recebe itens de origem e destino
              QGraphicsItem *parent = 0, QGraphicsScene *scene = 0); // Parâmetros opcionais para item pai e cena
    enum { Type = UserType + 4 }; // Define um tipo para o item
    int type() const // Método para obter o tipo do item
    { return Type; }
    QRectF boundingRect() const; // Método para obter o retângulo delimitador do item
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget); // Método para desenhar o item
    void updatePosition(); // Método para atualizar a posição do item
    CircuitItem* getSrc(); // Metodo para retornar o ponteiro para a origem do conector
    CircuitItem* getDst(); // Metodo para retornar o ponteiro para a saida do conector


protected:
           // void mousePressEvent(QGraphicsSceneMouseEvent *event);
           // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
           // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x, y; // Variáveis para coordenadas
    qreal radius, dstWidth, dstHeight; // Variáveis para o raio e dimensões do destino
    QColor color, lineColor, circleColor; // Cores para o item
    QPointF srcCenter, dstCenter; // Pontos centrais dos itens de origem e destino
    QLineF centerLine; // Linha central do item
    QLineF borderVector; // Vetor de borda do item
    QPointF borderPoint; // Ponto de borda do item
    CircuitItem *src, *dst; // Ponteiros para os itens de origem e destino
};

#endif
