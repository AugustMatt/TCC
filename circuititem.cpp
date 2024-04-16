#include "circuititem.h" // Inclui o cabeçalho da classe CircuitItem
#include "conector.h" // Inclui o cabeçalho da classe Connector
#include <QtGui> // Inclui o cabeçalho para elementos gráficos do Qt
#include <QtSvg> // Inclui o cabeçalho para trabalhar com SVG
#include <iostream> // Inclui o cabeçalho para entrada e saída padrão
#include <QGraphicsScene>
#include <QDebug>

CircuitItem::CircuitItem(QString _itemType){ // Implementação do construtor da classe CircuitItem
    itemType = _itemType; // Inicializa o tipo do item com o valor passado como parâmetro
    svgrenderer=NULL; // Inicializa o renderizador SVG como nulo
    QString rec(":"); // Cria uma string com dois pontos
    itemName = itemType; // Inicializa o nome do item com o tipo do item
    rec = rec+itemType; // Concatena o tipo do item à string com dois pontos
    svgrenderer = new QSvgRenderer(rec); // Cria um novo renderizador SVG com o nome do arquivo SVG
    width =70; // Define a largura do item como 65 pixels
    height = 70; // Define a altura do item como 65 pixels
    rect.setRect(0,0,width,height); // Define o retângulo delimitador do item

    // Inicialização padrão para ler imagem em RGG no load image
    m_colorPattern = "RGB";

    // Define as flags do item para permitir movimentação, seleção e envio de alterações de geometria
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void CircuitItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){ // Implementação do método paint
    Q_UNUSED(widget); // Evita avisos de compilador sobre parâmetro não utilizado
    Q_UNUSED(option); // Evita avisos de compilador sobre parâmetro não utilizado

    QRect imageRect(rect); // Define um retângulo para a imagem
    QRect textRect(rect); // Define um retângulo para o texto
    QFont foo = painter->font(); // Obtém a fonte atual do pintor
    QFontMetrics fm(foo); // Obtém as métricas da fonte
    textHeightinPixels = fm.height(); // Obtém a altura do texto
    textRect.setHeight(height+textHeightinPixels); // Ajusta a altura do retângulo de texto

    if(
        itemType.compare(QString("INPUT"))==0
        || itemType.compare(QString("OUTPUT"))==0
        || itemType.compare(QString("LOADIMAGE"))==0
        || itemType.compare(QString("SHOWIMAGE"))==0)
    { // Verifica se o tipo do item é INPUT ou OUTPUT
        rect=textRect; // Atualiza o retângulo do item para incluir o texto
    }

    QSize size(svgrenderer->defaultSize()); // Obtém o tamanho padrão do SVG
    size.scale(imageRect.size(), Qt::KeepAspectRatio); // Escala o tamanho para manter a proporção
    imageRect.setSize(size); // Define o tamanho da imagem
    imageRect.moveTo(imageRect.x(), imageRect.y()); // Move a imagem para a posição correta

    if(svgrenderer->isValid() && svgrenderer != NULL){ // Verifica se o renderizador SVG é válido
        svgrenderer->render(painter, imageRect); // Renderiza o SVG no pintor na posição especificada
    }

    // Texto esta bugando
    if(
        itemType.compare(QString("INPUT"))==0
        || itemType.compare(QString("OUTPUT"))==0
        || itemType.compare(QString("LOADIMAGE"))==0
        || itemType.compare(QString("SHOWIMAGE"))==0)
    { // Verifica se o tipo do item é INPUT ou OUTPUT
        painter->drawText(textRect,Qt::AlignBottom|Qt::AlignHCenter,itemName); // Desenha o texto no retângulo de texto
    }

    // Adicionar lógica para desenhar a borda azul quando selecionado
    if (isSelected()) {
        painter->setPen(Qt::blue);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect());
    } else {
        painter->setPen(Qt::transparent);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect());
    }
}

void CircuitItem::addInputConnector(Connector *connector){ // Implementação do método para adicionar um conector de entrada
    inputConnectors.append(connector); // Adiciona o conector à lista de conectores de entrada
}

void CircuitItem::addOutputConnector(Connector *connector){ // Implementação do método para adicionar um conector de saída
    outputConnectors.append(connector); // Adiciona o conector à lista de conectores de saída
}

int CircuitItem::nInputs(void){ // Implementação do método para obter o número de entradas
    return inputConnectors.size(); // Retorna o tamanho da lista de conectores de entrada
}

QRectF CircuitItem::boundingRect() const{ // Implementação do método para obter o retângulo delimitador
    if(
        itemType.compare(QString("INPUT"))==0
        || itemType.compare(QString("OUTPUT"))==0
        || itemType.compare(QString("LOADIMAGE"))==0
        || itemType.compare(QString("SHOWIMAGE"))==0){ // Verifica se o tipo do item é INPUT ou OUTPUT
        return QRectF(0,0,width,height+textHeightinPixels); // Retorna o retângulo que inclui o texto
    }
    return QRectF(0,0,width,height); // Retorna o retângulo sem o texto
}

QVariant CircuitItem::itemChange(GraphicsItemChange change, const QVariant &value){ // Implementação do método para alterar propriedades do item
    if (change == QGraphicsItem::ItemPositionChange) { // Verifica se a mudança é na posição do item
        foreach (Connector *connector, inputConnectors) { // Itera sobre os conectores de entrada
            connector->updatePosition(); // Atualiza a posição do conector
        }
        foreach (Connector *connector, outputConnectors) { // Itera sobre os conectores de saída
            connector->updatePosition(); // Atualiza a posição do conector
        }
    }
    return (value); // Retorna o valor da mudança
}

QPointF CircuitItem::center(){ // Implementação do método para obter o centro do item
    return QPointF(x()+width/2,y()+width/2); // Retorna o ponto central do item
}

QPainterPath CircuitItem::shape() const{ // Implementação do método para obter o formato do item
    QPainterPath path; // Cria um caminho
    path.addEllipse(boundingRect()); // Adiciona uma elipse ao caminho com base no retângulo delimitador
    return path; // Retorna o caminho
}

QString CircuitItem::getType(){ // Implementação do método para obter o tipo do item
    return itemType; // Retorna o tipo do item
}

int CircuitItem::numberOfConnections(){ // Implementação do método para obter o número de conexões
    return inputConnectors.size(); // Retorna o tamanho da lista de conectores de entrada
}

QString CircuitItem::colorPattern() const
{
    return m_colorPattern;
}

void CircuitItem::setColorPattern(const QString &pattern)
{
    m_colorPattern = pattern;
}

QList<Connector *> CircuitItem::getInputConnectors(){
    return inputConnectors;
}

void CircuitItem::removeInputConnector(Connector *connector) {
    inputConnectors.removeOne(connector);
}

void CircuitItem::removeOutputConnector(Connector *connector) {
    outputConnectors.removeOne(connector);
}
