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


void CircuitViewer::play()
{
    QList<QGraphicsItem*> selectedItemsList = scene->selectedItems();

    if (!selectedItemsList.isEmpty()) {
        QGraphicsItem *selectedItem = selectedItemsList.first(); // Obtém o primeiro item selecionado
        CircuitItem *circuitItem = qgraphicsitem_cast<CircuitItem *>(selectedItem);

        if (circuitItem) {
            if (circuitItem->getType().compare(QString("LOADIMAGE")) == 0) {
                openImageFileDialog();
            } else if (circuitItem->getType().compare(QString("SHOWIMAGE")) == 0) {
                if (!circuitItem->getInputConnectors().isEmpty()) {
                    if (!circuitItem->getInputConnectors()[0]->getSrc()->image.empty()) {
                        QString windowName = "Imagem_" + QString::number(reinterpret_cast<std::uintptr_t>(circuitItem));
                        std::string windowNameStd = windowName.toStdString();
                        cv::namedWindow(windowNameStd.c_str(), cv::WINDOW_NORMAL);
                        cv::imshow(windowNameStd.c_str(), circuitItem->getInputConnectors()[0]->getSrc()->image);
                        cv::waitKey(0);
                    } else {
                        qDebug() << "Sem imagem para mostrar";
                    }
                } else {
                    qDebug() << "Sem conexão no SHOWIMAGE";
                }
            } else {
                qDebug() << "Função não implementada.";
            }
        } else {
            qDebug() << "Item selecionado não é um CircuitItem.";
        }
    } else {
        qDebug() << "Nenhum item selecionado.";
    }
}

// Função para converter QImage para cv::Mat
cv::Mat QImageToCvMat(const QImage &image) {
    cv::Mat matImage(image.height(), image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine());
    return matImage.clone();
}

void CircuitViewer::openImageFileDialog() {
    QList<QGraphicsItem*> selectedItemsList = scene->selectedItems();

    if (!selectedItemsList.isEmpty()) {
        QGraphicsItem *selectedItem = selectedItemsList.first(); // Obtém o primeiro item selecionado
        CircuitItem *circuitItem = qgraphicsitem_cast<CircuitItem *>(selectedItem);

        if (circuitItem && circuitItem->getType().compare(QString("LOADIMAGE")) == 0) {
            QString filePath = QFileDialog::getOpenFileName(this, "Selecionar Imagem", QDir::homePath(), "Imagens (*.png *.jpg *.bmp)");
            if (!filePath.isEmpty()) {
                QImage image(filePath);
                if (!image.isNull()) {
                    // Verifica o padrão de cor selecionado
                    QString colorPattern = circuitItem->colorPattern();
                    if (colorPattern == "RGB") {
                        // Converte a QImage para cv::Mat com padrão RGB
                        cv::Mat matImage = cv::Mat(image.height(), image.width(), CV_8UC3);
                        cv::cvtColor(QImageToCvMat(image), matImage, cv::COLOR_RGBA2RGB);
                        circuitItem->image = matImage;
                    } else if (colorPattern == "Escala de Cinza") {
                        // Converte a QImage para cv::Mat em escala de cinza
                        cv::Mat matImage = cv::Mat(image.height(), image.width(), CV_8UC1);
                        cv::cvtColor(QImageToCvMat(image), matImage, cv::COLOR_RGBA2GRAY);
                        circuitItem->image = matImage;
                    } else {
                        qDebug() << "Padrão de cor não suportado.";
                        return;
                    }

                    qDebug() << "Imagem atualizada no LOADIMAGE";
                    //cv::namedWindow("Imagem Selecionada", cv::WINDOW_NORMAL); // Cria uma janela com tamanho personalizado
                    //cv::imshow("Imagem Selecionada", circuitItem->image); // Exibe a imagem na janela
                    //cv::waitKey(0); // Espera até que uma tecla seja pressionada
                } else {
                    qDebug() << "Erro ao carregar a imagem.";
                }
            }
        } else {
            qDebug() << "Item selecionado não é um LOADIMAGE.";
        }
    } else {
        qDebug() << "Nenhum item selecionado.";
    }
}
