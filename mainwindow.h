#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMouseEvent>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPixmap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_horizontalSlider_R_valueChanged(int value);

    void on_horizontalSlider_S_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmap;
    QPixmap *mouse;
    bool right = true;
    int rotate = 0;
    double shear = 0;

    void drawAxes();
    void drawMouse();
    void transformMouse();
};

#endif // MAINWINDOW_H
