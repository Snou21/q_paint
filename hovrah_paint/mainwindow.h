#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter> // !
#include <QCursor>
#include <QPoint>
#include <QMouseEvent>
#include <QPixmap>
#include <QSlider>
#include <QFrame>
#include <QListWidgetItem>
#include <QPushButton>
#include <QQueue>
#include <QGuiApplication>
#include <QGuiApplication>
#include <QImage>
#include <QColor>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Tool{
        Brush,
        Eraser,
        Rect,
        Lasso,
        Line,
        Elipse,
        Fill,
        Dropper
    };

    Tool currentTool;
private:
    Ui::MainWindow *ui;
    QImage canvas;
    QPoint startPoint;
    QPoint lastPoint;
    bool drawing;
    QColor currentCol;
    int currentSize;
    QPushButton *brush;
    QPushButton *eraser;
    QPushButton *rect;
    QPushButton *lasso;
    QPushButton *line;
    QPushButton *elipse;
    QPushButton *fill;
    QPushButton *dropper;
    QSlider *sliderH;
    QSlider *sliderS;
    QSlider *sliderV;
    int h, s, v;
    double canvasScale;
    QPointF scaledPos; // важно при увеличении
    QPointF offset; // смещение в сторону курсора
    QPoint cursorPos;

protected:
    void mousePressEvent(QMouseEvent *event) override; // переопределение функции mousePressEvent
    void paintEvent(QPaintEvent *) override; // переопределение функции paintEvent
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
private slots:
    void on_pushButton_clicked();
    void on_lineEdit_bsize_editingFinished();
    void updateSize();
    void updateColor();
    void on_save_col_clicked();
    void on_color_selected(QListWidgetItem *item);
    void fill_tool(const QPoint& point, const QColor& newColor);
    void scr_color_pick();
};


#endif // MAINWINDOW_H
