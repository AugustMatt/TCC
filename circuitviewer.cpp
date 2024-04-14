#include "circuitviewer.h" // Inclui o arquivo de cabeçalho da classe CircuitViewer
#include "circuitscene.h" // Inclui o arquivo de cabeçalho da classe CircuitScene
#include <iostream> // Inclui a biblioteca para entrada e saída padrão
#include <QAction> // Inclui a biblioteca QAction para lidar com ações
#include "circuititem.h"
#include "conector.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QDebug>

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


void CircuitViewer::play(void){

    if (scene->selectedCircuitItem) {

        if(scene->selectedCircuitItem->itemType.compare(QString("LOADIMAGE"))==0){
            openImageFileDialog();
        } else if(scene->selectedCircuitItem->itemType.compare(QString("SHOWIMAGE"))==0){


            //Nesse caso espera-se que SHOWIMAGE so tenha um conector de entrada
            if (!scene->selectedCircuitItem->inputConnectors.isEmpty()) {
                if(!scene->selectedCircuitItem->inputConnectors[0]->src->image.empty()){
                    QString windowName = "Imagem_" + QString::number(reinterpret_cast<std::uintptr_t>(scene->selectedCircuitItem));
                    std::string windowNameStd = windowName.toStdString();
                    cv::namedWindow(windowNameStd.c_str(), cv::WINDOW_NORMAL); // Cria uma janela com tamanho personalizado
                    cv::imshow(windowNameStd.c_str(), scene->selectedCircuitItem->inputConnectors[0]->src->image); // Exibe a imagem na janela
                    cv::waitKey(0); // Espera até que uma tecla seja pressionada
                } else {
                    qDebug() << "Sem imagem para mostrar";
                }
            } else {
                qDebug() << "Sem conexão no SHOWIMAGE";
            }

            // Exemplo de iteração sobre os conectores de entrada do bloco selecionado
            /*
            foreach (Connector *connector, scene->selectedCircuitItem->inputConnectors) {
                if (connector->dst->itemType.compare(QString("SHOWIMAGE"))==0) {
                    // O CircuitItem 'item' está conectado ao bloco ShowImage
                    // Faça o que for necessário aqui
                }
            }
            */


        } else {
            qDebug() << "Função não implementada.";
        }

    } else {
        qDebug() << "Nenhum item selecionado.";
    }
}

void CircuitViewer::openImageFileDialog() {
    QString filePath = QFileDialog::getOpenFileName(this, "Selecionar Imagem", QDir::homePath(), "Imagens (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty()) {
        QImage image(filePath);
        if (!image.isNull()) {
            // Converte a QImage para cv::Mat se necessário
            cv::Mat matImage = cv::Mat(image.height(), image.width(), CV_8UC4, image.bits(), image.bytesPerLine()).clone();
            scene->selectedCircuitItem->image = matImage;
            qDebug() << "Imagem atualizada no LOADIMAGE";
            //cv::namedWindow("Imagem Selecionada", cv::WINDOW_NORMAL); // Cria uma janela com tamanho personalizado
            //cv::imshow("Imagem Selecionada", scene->selectedCircuitItem->image); // Exibe a imagem na janela
            //cv::waitKey(0); // Espera até que uma tecla seja pressionada
        } else {
            qDebug() << "Erro ao carregar a imagem.";
        }
    }
}
