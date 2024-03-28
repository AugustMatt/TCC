#ifndef VIEW_H
#define VIEW_H

#include <QFrame> // Inclui o cabeçalho para QFrame

// Declarações adiantadas para evitar a inclusão completa dos cabeçalhos das classes
QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QToolButton)

class View : public QFrame // Classe View é uma subclasse de QFrame
{
    Q_OBJECT // Macro para suportar funcionalidades como sinais e slots

public:
    // Construtor para criar uma nova instância da visualização com um nome e widget pai
    View(const QString &name, QWidget *parent = 0);

    QGraphicsView *view() const; // Método para retornar um ponteiro para QGraphicsView

private slots:
    // Métodos para manipulação da visualização
    void resetView();
    void setResetButtonEnabled();
    void setupMatrix();
    void toggleOpenGL();
    void toggleAntialiasing();
    void print();

    // Métodos para operações de zoom e rotação
    void zoomIn();
    void zoomOut();
    void rotateLeft();
    void rotateRight();

private:
    // Membros privados da classe
    QGraphicsView *graphicsView; // Visualização gráfica
    QLabel *label; // Rótulo
    QToolButton *openGlButton; // Botão para alternar OpenGL
    QToolButton *antialiasButton; // Botão para alternar antialiasing
    QToolButton *printButton; // Botão para imprimir
    QToolButton *resetButton; // Botão para redefinir
    QSlider *zoomSlider; // Controle deslizante para zoom
    QSlider *rotateSlider; // Controle deslizante para rotação
};

#endif // VIEW_H
