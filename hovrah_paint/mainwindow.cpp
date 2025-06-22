#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // конструктор
    : QMainWindow(parent), drawing(false),
    ui(new Ui::MainWindow),
    currentCol(Qt::black),
    currentTool(Tool::Brush),
    canvasScale(1.0),
    offset(QPointF(0, 0))
{
    ui->setupUi(this);
    canvas = QImage(1280, 720, QImage::Format_ARGB32);
    canvas.fill(Qt::white);

    setFixedSize(canvas.size());
    currentSize = ui->horizontalSlider->value();

    sliderH = ui->h;
    sliderS = ui->s;
    sliderV = ui->v;

    // инструменты
    brush = ui->brush;
    eraser = ui->eraser;
    rect = ui->rect;
    lasso = ui->lasso;
    line = ui->line;
    elipse = ui->elipse;
    fill = ui->fill;
    dropper = ui->dropper;

    connect(brush, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Brush;
        ui->cur_tool->setText("Brush");
    });
    connect(eraser, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Eraser;
        ui->cur_tool->setText("Eraser");
    });
    connect(rect, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Rect;
        ui->cur_tool->setText("Rect");
    });
    connect(lasso, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Lasso;
        ui->cur_tool->setText("Lasso");
    });
    connect(line, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Line;
        ui->cur_tool->setText("Line");
    });
    connect(elipse, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Elipse;
        ui->cur_tool->setText("Elipse");
    });
    connect(fill, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Fill;
        ui->cur_tool->setText("Fill");
    });
    connect(dropper, &QPushButton::pressed, this, [=](){
        currentTool = Tool::Dropper;
        ui->cur_tool->setText("Dropper");
    });
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::updateSize);
    connect(sliderH, &QSlider::valueChanged, this, &MainWindow::updateColor);
    connect(sliderS, &QSlider::valueChanged, this, &MainWindow::updateColor);
    connect(sliderV, &QSlider::valueChanged, this, &MainWindow::updateColor);

    connect(ui->col_list, &QListWidget::itemClicked, this, &MainWindow::on_color_selected);

    updateSize();
    updateColor();

}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);


    painter.translate(offset);
    painter.scale(canvasScale, canvasScale);
    painter.drawImage(0, 0, canvas); // отрисовка холста(pixmap)

    // рисуем (НЕОКОНЧАТЕЛЬНО)
    if (drawing) {
        painter.setPen(QPen(currentCol, currentSize, Qt::SolidLine, Qt::RoundCap));
        if (currentTool == Tool::Rect){
            QRect rect(startPoint, lastPoint);
            painter.drawRect(rect);  // рисуем временный прямоугольник

        }
        if (currentTool == Tool::Line){
            QLine line(startPoint, lastPoint);
            painter.drawLine(line);
        }
        if (currentTool == Tool::Elipse){
            QRect rect(startPoint, lastPoint);
            painter.drawEllipse(rect);  // рисуем временный прямоугольник
        }
    }

    // отрисовка курсора(кружечка)
    painter.resetTransform(); // чтобы нарисовать в экранных координатах
    painter.setPen(QPen(Qt::gray, 2, Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    int r = (currentSize / 2) * canvasScale;
    painter.drawEllipse(cursorPos , r, r);

}

void MainWindow::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        drawing = true;
        scaledPos = (event->pos() - offset) / canvasScale;
        startPoint = scaledPos.toPoint();
        lastPoint = startPoint;
        update();

        QPoint pos = ((event->pos() - offset) / canvasScale).toPoint();
        if (currentTool == Tool::Fill) {
            fill_tool(pos, currentCol);
        }
        if (currentTool == Tool::Dropper){
            scr_color_pick();
        }
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    // рисуем (ОКОНЧАТЕЛЬНО)
    if (event->button() == Qt::LeftButton) {
        QPainter painter(&canvas);
        painter.setPen(QPen(currentCol, currentSize, Qt::SolidLine, Qt::RoundCap));

        if(currentTool == Tool::Rect){
            QRect rect(startPoint, ((event->pos() - offset) /canvasScale).toPoint());
            painter.drawRect(rect);  // финальный прямоугольник на холсте
        }
        if(currentTool == Tool::Line){
            QLine line(startPoint, lastPoint);
            painter.drawLine(line);
        }
        if(currentTool == Tool::Elipse){
            QRect rect(startPoint, ((event->pos() - offset) /canvasScale).toPoint());
            painter.drawEllipse(rect);
        }
    }
    drawing = false;
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    cursorPos = event->pos();
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        QPainter painter(&canvas); // задаем холст, где можно рисовать

        if(currentTool == Tool::Brush){
            painter.setPen(QPen(currentCol, currentSize, Qt::SolidLine, Qt::RoundCap)); //
            painter.drawLine(lastPoint, (event->pos() - offset) /canvasScale ); // отрисовка линии
            lastPoint = ((event->pos() - offset) /canvasScale).toPoint();
        }else if(currentTool == Tool::Eraser){
            painter.setPen(QPen(Qt::white, currentSize, Qt::SolidLine, Qt::RoundCap)); //
            painter.drawLine(lastPoint, (event->pos() - offset) /canvasScale); // отрисовка линии
            lastPoint = ((event->pos() - offset) /canvasScale).toPoint();
        }else if(currentTool == Tool::Lasso){
            painter.setPen(QPen(currentCol, currentSize, Qt::SolidLine, Qt::RoundCap)); //
            painter.drawLine(lastPoint,(event->pos() - offset) /canvasScale); // отрисовка линии
        }
        else if(currentTool == Tool::Rect || currentTool == Tool::Line || currentTool == Tool::Elipse){
            lastPoint = ((event->pos() - offset) /canvasScale).toPoint(); // обновление позиции
        }
        update(); // обновляем виджет
    }

}

void MainWindow::wheelEvent(QWheelEvent *event) {

    double oldScale = canvasScale;

    if (event->angleDelta().y() > 0)
        canvasScale *= 1.1; // увеличиваем
    else
        canvasScale /= 1.1; // уменьшаем

    canvasScale = std::clamp(canvasScale, 0.5, 20.0); // ограничение

    QPointF beforeScale = (event->position() - offset) / oldScale;
    QPointF afterScale = (event->position() - offset) / canvasScale;

    QPointF delta = (afterScale - beforeScale) * canvasScale;

    offset += delta;

    update(); // перерисовать
}

MainWindow::~MainWindow()
{
    delete ui;
}

// очистить холст
void MainWindow::on_pushButton_clicked()
{
    canvas.fill(Qt::white);
    update(); // обновляем виджет
}


// размер кисти
void MainWindow::updateSize(){
    currentSize = ui->horizontalSlider->value();
    ui->lineEdit_bsize->setText(QString::number(currentSize));
}
void MainWindow::on_lineEdit_bsize_editingFinished()
{
    ui->horizontalSlider->setValue(ui->lineEdit_bsize->text().toInt());
}

void MainWindow::updateColor()
{
    h = sliderH->value();
    s = sliderS->value();
    v = sliderV->value();

    currentCol.setHsv(h, s, v);
    ui->col_prev->setStyleSheet(QString("background-color: %1").arg(currentCol.name()));
    ui->col->setText(QString::number(h) + " " + QString::number(s) + " " +  QString::number(v));
}


void MainWindow::on_save_col_clicked()
{
    QListWidgetItem *item = new QListWidgetItem(QString("%1 %2 %3").arg(h).arg(s).arg(v)); // элемент списка
    item->setData(Qt::UserRole, QVariant::fromValue(QVector3D(h, s, v))); // вставка текущих hsv, используя vector3D
    ui->col_list->addItem(item);

}

void MainWindow::on_color_selected(QListWidgetItem *item) // выбор цвета из листа
{
    QVector3D hsv = item->data(Qt::UserRole).value<QVector3D>();

    h = hsv.x();
    s = hsv.y();
    v = hsv.z();

    sliderH->setValue(h);
    sliderS->setValue(s);
    sliderV->setValue(v);

    updateColor();
}

void MainWindow::fill_tool(const QPoint &point, const QColor &newColor)
{
    if (!canvas.rect().contains(point)) return;

    QColor targetColor = canvas.pixelColor(point);
    if (targetColor == newColor) return;

    QQueue<QPoint> queue;
    queue.enqueue(point);

    while (!queue.isEmpty()) {
        QPoint p = queue.dequeue();

        if (!canvas.rect().contains(p)) continue;
        if (canvas.pixelColor(p) != targetColor) continue;

        canvas.setPixelColor(p, newColor);

        queue.enqueue(QPoint(p.x() + 1, p.y()));
        queue.enqueue(QPoint(p.x() - 1, p.y()));
        queue.enqueue(QPoint(p.x(), p.y() + 1));
        queue.enqueue(QPoint(p.x(), p.y() - 1));
    }

    update();

}

void MainWindow::scr_color_pick()
{
    QPoint cursorPos = QCursor::pos(); // глобальные координаты курсора

    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return;

    QPixmap screenshot = screen->grabWindow(0, cursorPos.x(), cursorPos.y(), 1, 1);
    QImage image = screenshot.toImage();
    QColor pickedColor = image.pixelColor(0, 0);

    currentCol = pickedColor;

    QListWidgetItem *item = new QListWidgetItem(QString("%1 %2 %3").arg(h).arg(s).arg(v)); // элемент списка
    item->setData(Qt::UserRole, QVariant::fromValue(QVector3D(h, s, v))); // вставка текущих hsv, используя vector3D
    ui->col_list->addItem(item);
}



