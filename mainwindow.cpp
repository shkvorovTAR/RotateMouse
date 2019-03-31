#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_X 800
#define MAX_Y 600

void MainWindow::transformMouse()
{
    QTransform transform;
    if(right)
    {
        ui->label_2->setText("<img src = ':/img/img/layToRigth.png' width='115'  height='30'>");
        transform.scale(-1, 1);
    }
    else {
        ui->label_2->setText("<img src = ':/img/img/lay.png' width='115'  height='30'>");
        transform.scale(1, 1);
    }
    transform.rotate(rotate);
    transform.shear(shear, shear);
    transform.translate(-MAX_X/2-60,-MAX_Y/2);
    pixmap->setTransform(transform);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->x() > MAX_X/2) {
        right = true;
    }else {
        right = false;
    }

    transformMouse();
}

void MainWindow::drawAxes()
{
    int half_X = MAX_X/2;
    int half_Y = MAX_Y/2;

    scene->addLine(0,0,half_X,0);
    scene->addLine(0,0,0,half_Y);

    scene->addLine(0,0,-half_X,0);
    scene->addLine(0,0,0,-half_Y);

    scene->addRect(-half_X, -half_Y, MAX_X, MAX_Y,
                   QPen(Qt::DotLine));
}

void MainWindow::drawMouse()
{
    QPixmap src = QPixmap(":/img/img/stand.png");
    pixmap = new QGraphicsPixmapItem(src);
    //pixmap->setPos


    scene->addItem(pixmap);
    pixmap->setScale(0.6);
    pixmap->setTransformOriginPoint(pixmap->boundingRect().center());
//    QTransform transform = QTransform();
//    int w = pixmap->pixmap().width();
//    qDebug() << w;
//    //transform.translate(100, 0);
//    //pixmap->setTransform(transform);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->
            setStyleSheet("background-color: white;");


    this->setFixedSize(MAX_X+50,MAX_Y+150);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    int half_X = MAX_X/2;
    int half_Y = MAX_Y/2;
    scene->setSceneRect(-half_X,-half_Y, MAX_X, MAX_Y);
    drawAxes();
    drawMouse();
    transformMouse();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_R_valueChanged(int value)
{
    rotate = value;
    ui->label_R->setText(QString::number(rotate) + "°");
    transformMouse();
}

void MainWindow::on_horizontalSlider_S_valueChanged(int value)
{
    shear = value / 100.0;
    QString strVal;
    strVal.sprintf("%.2f", shear);
    ui->label_S->setText(strVal);
    transformMouse();
}
