#ifndef CIRCUITVIEWER_H
#define CIRCUITVIEWER_H

#include <QGraphicsView> // Inclui a biblioteca QGraphicsView para a exibição gráfica
#include <QFileDialog> // Inclui a biblioteca QFileDialog para lidar com diálogos de arquivos

class CircuitScene; // Declaração antecipada da classe CircuitScene para evitar dependências circulares

class CircuitViewer : public QGraphicsView // Declaração da classe CircuitViewer, que herda de QGraphicsView
{
    Q_OBJECT // Macro necessária para suportar recursos de metadados do Qt
public:
    explicit CircuitViewer(QWidget *parent = 0); // Construtor da classe CircuitViewer

signals: // Definição de sinais da classe

public slots: // Definição de slots da classe
    void mousePressEvent(QMouseEvent *event); // Slot para lidar com eventos de clique do mouse
    void addItem(QAction *action); // Slot para adicionar um item ao circuito
    void setMode(QAction *action); // Slot para definir o modo de operação do circuito
    void record(void); // Slot para gravar o circuito

private:
    CircuitScene *scene; // Ponteiro para a cena do circuito
};

#endif // CIRCUITVIEWER_H
