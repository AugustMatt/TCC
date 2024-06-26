#ifndef CIRCUITSCENE_H
#define CIRCUITSCENE_H

#include <QGraphicsScene> // Inclui a biblioteca QGraphicsScene para gerenciar uma cena gráfica
#include <conector.h>
#include <QGridLayout>
#include <QLineEdit>

class CircuitItem; // Declaração antecipada da classe CircuitItem para evitar dependências circulares

enum {LINE, POINTER}; // Enumeração para definir os modos de operação (linha ou ponteiro)

class CircuitScene : public QGraphicsScene // Declaração da classe CircuitScene, que herda de QGraphicsScene
{
    Q_OBJECT // Macro necessária para suportar recursos de metadados do Qt
public:
    explicit CircuitScene(QObject *parent = 0); // Construtor da classe CircuitScene
    bool isItemChange(int type); // Verifica se houve alteração em um tipo de item específico
    int record(QString filename); // Grava a cena em um arquivo especificado


public slots: // Definição de slots da classe
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // Slot para lidar com eventos de clique do mouse
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override; // Slot para lidar com eventos de movimento do mouse
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override; // Slot para lidar com eventos de liberação do mouse
    void setMode(QString s); // Slot para definir o modo de operação da cena
    void add(QString s); // Slot para adicionar um item à cena
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    CircuitItem *item; // Ponteiro para o item do circuito
    QGraphicsLineItem *line; // Ponteiro para o item de linha gráfica
    int mode; // Variável para armazenar o modo de operação da cena

private slots:
    void openSelectedItemSettingsWindow();
};

#endif // CIRCUITSCENE_H
