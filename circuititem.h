#ifndef CIRCUITITEM_H
#define CIRCUITITEM_H

#include <QGraphicsItem> // Inclui o cabeçalho para itens gráficos do Qt
#include <QString> // Inclui o cabeçalho para manipulação de strings
#include <QtSvg> // Inclui o cabeçalho para trabalhar com SVG
#include <opencv2/opencv.hpp>

class QGraphicsSvgItem; // Declaração antecipada da classe QGraphicsSvgItem
class Connector; // Declaração antecipada da classe Connector

class CircuitItem : public QGraphicsItem // Define a classe CircuitItem como um subclasse de QGraphicsItem
{
public:
    enum { Type = UserType+1 }; // Define o tipo do item como UserType + 1
    int type() const { return Type; } // Retorna o tipo do item
    CircuitItem(QString _itemType); // Construtor da classe CircuitItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Método para desenhar o item
    QRectF boundingRect() const; // Retorna o retângulo delimitador do item
    QVariant itemChange(GraphicsItemChange change, const QVariant &value); // Método para alterar propriedades do item
    QPointF center(); // Retorna o centro do item
    QString getType(); // Retorna o tipo do item
    QPainterPath shape() const; // Retorna o formato do item
    int numberOfConnections(); // Retorna o número de conexões do item
    void addInputConnector(Connector *connector); // Adiciona um conector de entrada ao item
    void addOutputConnector(Connector *connector); // Adiciona um conector de saída ao item
    int nInputs(); // Retorna o número de entradas do item
    QList<Connector *> getInputConnectors(); // Retornar a lista de conectores de entrada
    void removeInputConnector(Connector *connector);
    void removeOutputConnector(Connector *connector);

    // Variaveis do openCv
    cv::Mat image; // Matriz de armazenamento da imagem (OpenCV)

    // Padrão de cor para bloco laod image
    QString colorPattern() const;
    void setColorPattern(const QString &pattern);

private:
    QString itemName; // Nome do item
    QSvgRenderer *svgrenderer; // Renderizador SVG
    QRect rect; // Retângulo do item
    int width, height; // Largura e altura do item
    int id; // ID do item
    int textWidthinPixels; // Largura do texto em pixels
    int textHeightinPixels; // Altura do texto em pixels
    QString itemType; // Tipo do item
    QList<Connector *> inputConnectors, outputConnectors; // Lista de conectores de entrada e saída do item

    QString m_colorPattern;


};

#endif // CIRCUITITEM_H
