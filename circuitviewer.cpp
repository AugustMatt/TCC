#include "circuitviewer.h" // Inclui o arquivo de cabeçalho da classe CircuitViewer
#include "circuitscene.h" // Inclui o arquivo de cabeçalho da classe CircuitScene
#include <iostream> // Inclui a biblioteca para entrada e saída padrão
#include <QAction> // Inclui a biblioteca QAction para lidar com ações

CircuitViewer::CircuitViewer(QWidget *parent) :
    QGraphicsView(parent) // Construtor da classe CircuitViewer
{
    scene = new CircuitScene(this); // Cria uma nova instância da classe CircuitScene
    setScene(scene); // Define a cena do circuito para a cena criada
    setAlignment(Qt::AlignLeft|Qt::AlignTop); // Define o alinhamento da cena
    scene->setBackgroundBrush(QBrush(QColor(230,230,230), Qt::CrossPattern)); // Define o pano de fundo da cena
    setRenderHint(QPainter::Antialiasing); // Define o antialiasing para melhorar a renderização
}

void CircuitViewer::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event); // Manipula o evento de clique do mouse
}

void CircuitViewer::addItem(QAction *action){
    scene->add(action->iconText()); // Adiciona um item à cena com base no texto do ícone da ação
}

void CircuitViewer::setMode(QAction *action){
    scene->setMode(action->iconText()); // Define o modo de operação da cena com base no texto do ícone da ação
}

void CircuitViewer::record(void){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File")); // Abre um diálogo de salvar arquivo
    std::cout << "record:" << fileName.toStdString() << "\n"; // Exibe o nome do arquivo de gravação no console
    scene->record(fileName); // Grava o circuito no arquivo especificado
}
