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
    QString colorPattern() const; // Método para retornar o padrão de cor no laod image
    void setColorPattern(const QString &pattern); // Metodo para alterar o padrão de cor no load image

    void setMatrix(const QVector<QVector<float>>& mat); // Método para definir a matriz
    QVector<QVector<float>> getMatrix() const; // Método para obter a matriz
    void setDivisibility(float div); // Método para definir a divisibilidade
    float getDivisibility() const; // Método para obter a divisibilidade


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

    // Variaveis do opencv
    QString m_colorPattern; // Padrão de cor no load image
    QVector<QVector<float>> convolutionKernel; // Matriz para armazenar os valores de uma convolução
    float divisibility = 1.0; // Número para dividir todos os elementos da matriz


};

#endif // CIRCUITITEM_H
