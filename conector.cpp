#include "conector.h" // Inclui o cabeçalho da classe Connector
#include "circuititem.h" // Inclui o cabeçalho da classe CircuitItem
#include <QtGui> // Inclui o cabeçalho principal do Qt
#include <iostream> // Inclui o cabeçalho para entrada e saída de dados
#include <QGraphicsScene>
#include <QDebug>
// Implementação do construtor da classe Connector
Connector::Connector(CircuitItem *_src, CircuitItem *_dst,
                     QGraphicsItem *parent, QGraphicsScene *scene)
    :QGraphicsLineItem(parent)//, scene)
{
    src = _src; // Define o item de origem
    dst = _dst; // Define o item de destino
    dstWidth = .5 * dst->boundingRect().bottomRight().rx(); // Calcula a largura do destino
    dstHeight = .5 * dst->boundingRect().bottomRight().ry(); // Calcula a altura do destino
    setZValue(0); // Define o valor Z do conector
    radius = 10; // Define o raio do círculo
    setFlags(ItemIsSelectable); // Define as flags do item (nesse caso, seleção)
    lineColor = Qt::black; // Define a cor da linha
    circleColor = Qt::red; // Define a cor do círculo
}

// Método para obter o retângulo delimitador do conector
QRectF Connector::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0 + radius; // Calcula o espaço extra
    return QRectF(line().p1(), // Retorna um retângulo com base nas coordenadas
                  QSizeF(line().p2().x() - line().p1().x(), // e no tamanho da linha
                         line().p2().y() - line().p1().y()))
        .normalized() // Normaliza o retângulo
        .adjusted(-extra, -extra, extra, extra); // Ajusta o retângulo com o espaço extra
}

// Método para atualizar a posição do conector
void Connector::updatePosition()
{
    srcCenter = src->center(); // Obtém o centro do item de origem
    dstCenter = dst->center(); // Obtém o centro do item de destino
    QLineF linha(srcCenter, dstCenter); // Cria uma linha entre os centros
    setLine(linha); // Define a linha do conector como essa linha
    centerLine.setP1(srcCenter); // Define o ponto inicial da linha central
    centerLine.setP2(dstCenter); // Define o ponto final da linha central
    borderVector = centerLine.unitVector(); // Calcula o vetor de borda
    borderPoint.setX(-dstWidth * borderVector.dx() + dstCenter.rx()); // Calcula o ponto de borda X
    borderPoint.setY(-dstHeight * borderVector.dy() + dstCenter.ry()); // Calcula o ponto de borda Y
    centerLine.setP2(borderPoint); // Define o ponto final da linha central como o ponto de borda
}

// Método para desenhar o conector
void Connector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget); // Evita o aviso de variável não utilizada
    Q_UNUSED(option); // Evita o aviso de variável não utilizada
    if (src->collidesWithItem(dst)) // Verifica se o item de origem colide com o item de destino
        return; // Retorna se houver colisão

    QPen myPen = pen(); // Obtém a caneta do pintor
    myPen.setWidth(3); // Define a largura da caneta
    if (isSelected()) {
        myPen.setColor(Qt::blue); // Define a cor da caneta como azul se o conector estiver selecionado
    } else {
        myPen.setColor(lineColor); // Define a cor da caneta normal
    }
    painter->setPen(myPen); // Define a caneta no pintor
    painter->setBrush(circleColor); // Define o pincel no pintor
    painter->drawLine(centerLine); // Desenha a linha do conector
    painter->drawEllipse(borderPoint, radius, radius); // Desenha o círculo do conector
}


