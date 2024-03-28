#include <QApplication> // Inclui a biblioteca QApplication para criar e gerenciar a aplicação Qt
#include "mainwindow.h" // Inclui o arquivo de declaração da classe MainWindow

//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Cria uma instância da classe QApplication para gerenciar a aplicação

    MainWindow w; // Cria uma instância da classe MainWindow, que é a janela principal da aplicação

    w.show(); // Exibe a janela principal na tela

    return a.exec(); // Inicia o loop de eventos da aplicação Qt e gerencia a execução da aplicação até que seja encerrada
}
