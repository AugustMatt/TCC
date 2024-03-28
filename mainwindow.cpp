#include "mainwindow.h" // Inclui o arquivo de cabeçalho da classe MainWindow
#include "ui_mainwindow.h" // Inclui o arquivo de cabeçalho gerado pelo Qt Designer para a interface gráfica

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), // Chama o construtor da classe base QMainWindow
    ui(new Ui::MainWindow) // Inicializa o ponteiro para a classe gerada pelo Qt Designer
{
    ui->setupUi(this); // Configura a interface gráfica conforme o arquivo gerado pelo Qt Designer
    pointTypeGroup = new QActionGroup(this); // Cria um novo grupo de ações
    pointTypeGroup->addAction(ui->actionPOINT); // Adiciona a ação POINT ao grupo de ações
    pointTypeGroup->addAction(ui->actionLINE); // Adiciona a ação LINE ao grupo de ações
    ui->actionPOINT->setChecked(true); // Define a ação POINT como selecionada por padrão
}

MainWindow::~MainWindow() // Destrutor da classe MainWindow
{
    delete ui; // Libera a memória alocada para a interface gráfica
}
