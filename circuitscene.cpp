#include "circuitscene.h" // Inclui o arquivo de cabeçalho da classe CircuitScene
#include "circuititem.h" // Inclui o arquivo de cabeçalho da classe CircuitItem
#include "conector.h" // Inclui o arquivo de cabeçalho da classe Connector
#include <iostream> // Inclui a biblioteca para entrada e saída padrão
#include <QtGui> // Inclui as bibliotecas gráficas do Qt
#include <QtSvg> // Inclui a biblioteca para trabalhar com SVG
#include <qgraphicssceneevent.h> // Inclui a biblioteca para eventos de cena gráfica

CircuitScene::CircuitScene(QObject *parent) :
    QGraphicsScene(parent) // Construtor da classe CircuitScene
{
    mode = POINTER; // Inicializa o modo de operação como POINTER por padrão
    connect(this, &CircuitScene::itemClicked, this, &CircuitScene::handleItemClick);
}

void CircuitScene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if (event->button() != Qt::LeftButton) // Verifica se o botão pressionado não é o botão esquerdo do mouse
        return;

    if(mode == LINE){ // Verifica se o modo de operação é LINE
        line = new QGraphicsLineItem(QLineF(event->scenePos(),event->scenePos())); // Cria um novo item de linha na cena
        addItem(line); // Adiciona o item de linha à cena
    }

    // Verificar se um item foi clicado
    QGraphicsItem* clickedItem = itemAt(event->scenePos(), QTransform());
    if (clickedItem && clickedItem->type() == CircuitItem::Type) {
        emit itemClicked(qgraphicsitem_cast<CircuitItem*>(clickedItem));
    }

    QGraphicsScene::mousePressEvent(event); // Chama a implementação padrão do evento de pressionar o mouse na cena
}

void CircuitScene::handleItemClick(CircuitItem* item) {
    if (item) {
        // Desselecionar o item atualmente selecionado
        if (selectedCircuitItem) {
            selectedCircuitItem->setSelected(false);
        }

        // Selecionar o item clicado
        item->setSelected(true);
        selectedCircuitItem = item;
    }
}

void CircuitScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(line != 0 && mode == LINE){ // Verifica se existe uma linha em criação e o modo é LINE
        QLineF newLine(line->line().p1(), event->scenePos()); // Define a nova posição da linha
        line->setLine(newLine); // Atualiza a linha com a nova posição
    }
    else{
        QGraphicsScene::mouseMoveEvent(event); // Chama a implementação padrão do evento de mover o mouse na cena
    }
}

void CircuitScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    if(line !=0 && mode == LINE){ // Verifica se existe uma linha em criação e o modo é LINE

        QList<QGraphicsItem *> startItems = items(line->line().p1()); // Obtém os itens no ponto inicial da linha

        if (startItems.count() && startItems.first() == line) // Verifica se o primeiro item é a própria linha
            startItems.removeFirst(); // Remove a linha da lista de itens iniciais

        QList<QGraphicsItem *> endItems = items(line->line().p2()); // Obtém os itens no ponto final da linha

        if (endItems.count() && endItems.first() == line) // Verifica se o primeiro item é a própria linha
            endItems.removeFirst(); // Remove a linha da lista de itens finais

        removeItem(line); // Remove a linha da cena
        delete line; // Libera a memória da linha
        line=0; // Define a linha como nula
        // Verifica se existem itens nos pontos inicial e final da linha, e se são do tipo CircuitItem
        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == CircuitItem::Type &&
            endItems.first()->type() == CircuitItem::Type &&
            startItems.first() != endItems.first()) {
            CircuitItem *startItem =
                qgraphicsitem_cast<CircuitItem *>(startItems.first()); // Converte o primeiro item para CircuitItem
            CircuitItem *endItem =
                qgraphicsitem_cast<CircuitItem *>(endItems.first()); // Converte o primeiro item para CircuitItem
            // Verifica se o endItem é um OUTPUT com entrada já definida
            if(endItem->getType().compare(QString("OUTPUT"))==0 &&
                endItem->numberOfConnections()>0){
                QGraphicsScene::mouseReleaseEvent(event); // Chama a implementação padrão do evento de liberação do mouse na cena
                return;
            }
            // Verifica se o endItem é um NOT com entrada já definida
            if(endItem->getType().compare(QString("NOT"))==0 &&
                endItem->nInputs()>0){
                QGraphicsScene::mouseReleaseEvent(event); // Chama a implementação padrão do evento de liberação do mouse na cena
                return;
            }
            // Verifica se o endItem é um INPUT
            if(endItem->getType().compare(QString("INPUT"))==0){
                QGraphicsScene::mouseReleaseEvent(event); // Chama a implementação padrão do evento de liberação do mouse na cena
                return;
            }
            // Verifica se o startItem é um OUTPUT
            if(startItem->getType().compare(QString("OUTPUT"))==0){
                QGraphicsScene::mouseReleaseEvent(event); // Chama a implementação padrão do evento de liberação do mouse na cena
                return;
            }
            // Cria um conector entre os itens startItem e endItem
            Connector *conector = new Connector(startItem, endItem);
            startItem->addOutputConnector(conector); // Adiciona o conector à saída do startItem
            endItem->addInputConnector(conector); // Adiciona o conector à entrada do endItem
            conector->setZValue(-1000.0); // Define a ordem de renderização do conector
            addItem(conector); // Adiciona o conector à cena
            conector->updatePosition(); // Atualiza a posição do conector
        }
    }
    QGraphicsScene::mouseReleaseEvent(event); // Chama a implementação padrão do evento de liberação do mouse na cena
}

void CircuitScene::add(QString s){
    item = new CircuitItem(s); // Cria um novo item do tipo CircuitItem com o texto fornecido
    addItem(item); // Adiciona o item à cena
}

void CircuitScene::setMode(QString s){
    if(s.compare("LINE")==0){ // Verifica se o modo fornecido é LINE
        mode = LINE; // Define o modo de operação como LINE
    }
    else{
        mode = POINTER; // Define o modo de operação como POINTER
    }
}

bool CircuitScene::isItemChange(int type)
{
    foreach (QGraphicsItem *item, selectedItems()) { // Itera sobre os itens selecionados na cena
        if (item->type() == type) // Verifica se o tipo do item corresponde ao tipo fornecido
            return true; // Retorna verdadeiro se encontrar um item do tipo especificado
    }
    return false; // Retorna falso se não encontrar nenhum item do tipo especificado
}

int CircuitScene::record(QString filename){
    QList<QGraphicsItem *> myitems; // Lista de itens gráficos
    QList<QGraphicsItem *>::iterator it; // Iterador para a lista de itens
    myitems = items(); // Obtém todos os itens da cena
    int count=0; // Contador de itens
    for(it = myitems.begin(); it != myitems.end(); it++, count++){ // Itera sobre todos os itens da cena
        std::cout << "count = " << count << "\n"; // Imprime o número do item
        if((*it)->type() == CircuitItem::Type){ // Verifica se o item é do tipo CircuitItem
            CircuitItem *theItem =
                qgraphicsitem_cast<CircuitItem *>(*it); // Converte o item para CircuitItem
            std::cout << "item " << theItem->getType().toStdString() << "\n"; // Imprime o tipo do item
        }
    }
    // endItem is an OUTPUT with input already defined
}
