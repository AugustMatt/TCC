#ifndef CIRCUITSCENE_H
#define CIRCUITSCENE_H

#include <QGraphicsScene> // Inclui a biblioteca QGraphicsScene para gerenciar uma cena gráfica

class CircuitItem; // Declaração antecipada da classe CircuitItem para evitar dependências circulares

enum {LINE, POINTER}; // Enumeração para definir os modos de operação (linha ou ponteiro)

class CircuitScene : public QGraphicsScene // Declaração da classe CircuitScene, que herda de QGraphicsScene
{
    Q_OBJECT // Macro necessária para suportar recursos de metadados do Qt
public:
    explicit CircuitScene(QObject *parent = 0); // Construtor da classe CircuitScene
    bool isItemChange(int type); // Verifica se houve alteração em um tipo de item específico
    int record(QString filename); // Grava a cena em um arquivo especificado
    CircuitItem* selectedCircuitItem = nullptr;

signals: // Definição de sinais da classe
    void itemClicked(CircuitItem* item);


public slots: // Definição de slots da classe
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // Slot para lidar com eventos de clique do mouse
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event); // Slot para lidar com eventos de movimento do mouse
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // Slot para lidar com eventos de liberação do mouse
    void setMode(QString s); // Slot para definir o modo de operação da cena
    void add(QString s); // Slot para adicionar um item à cena
    void handleItemClick(CircuitItem* item);


private:
    CircuitItem *item; // Ponteiro para o item do circuito
    QGraphicsLineItem *line; // Ponteiro para o item de linha gráfica
    int mode; // Variável para armazenar o modo de operação da cena
};

#endif // CIRCUITSCENE_H
