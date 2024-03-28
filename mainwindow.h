#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Inclui a biblioteca QMainWindow para criar a janela principal
#include <QActionGroup> // Inclui a biblioteca QActionGroup para agrupar ações

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow // Declaração da classe MainWindow, que herda de QMainWindow
{
    Q_OBJECT // Macro necessária para suportar recursos de metadados do Qt

public:
    explicit MainWindow(QWidget *parent = 0); // Construtor da classe MainWindow
    ~MainWindow(); // Destrutor da classe MainWindow

private:
    Ui::MainWindow *ui; // Ponteiro para a classe gerada pelo Qt Designer para a interface gráfica
    QActionGroup *pointTypeGroup; // Ponteiro para o grupo de ações relacionadas aos tipos de pontos

};

#endif // MAINWINDOW_H
