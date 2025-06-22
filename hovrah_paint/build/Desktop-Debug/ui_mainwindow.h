/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *col;
    QPushButton *brush;
    QPushButton *pushButton;
    QPushButton *elipse;
    QSlider *h;
    QSlider *s;
    QListWidget *col_list;
    QSlider *v;
    QPushButton *rect;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit_bsize;
    QPushButton *save_col;
    QLabel *col_prev;
    QPushButton *dropper;
    QPushButton *fill;
    QPushButton *line;
    QPushButton *eraser;
    QPushButton *lasso;
    QLabel *cur_tool;
    QFrame *line_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(839, 828);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 171, 761));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 169, 759));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-1, -1, 171, 811));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 11, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 20, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 9, 0, 1, 2);

        col = new QLabel(gridLayoutWidget);
        col->setObjectName("col");

        gridLayout->addWidget(col, 17, 0, 1, 1);

        brush = new QPushButton(gridLayoutWidget);
        brush->setObjectName("brush");
        QFont font;
        font.setPointSize(7);
        brush->setFont(font);

        gridLayout->addWidget(brush, 5, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 3, 0, 1, 2);

        elipse = new QPushButton(gridLayoutWidget);
        elipse->setObjectName("elipse");
        elipse->setFont(font);

        gridLayout->addWidget(elipse, 7, 1, 1, 1);

        h = new QSlider(gridLayoutWidget);
        h->setObjectName("h");
        h->setMaximum(359);
        h->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(h, 12, 0, 1, 2);

        s = new QSlider(gridLayoutWidget);
        s->setObjectName("s");
        s->setMaximum(255);
        s->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(s, 13, 0, 1, 2);

        col_list = new QListWidget(gridLayoutWidget);
        col_list->setObjectName("col_list");

        gridLayout->addWidget(col_list, 19, 0, 1, 2);

        v = new QSlider(gridLayoutWidget);
        v->setObjectName("v");
        v->setMaximum(255);
        v->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(v, 14, 0, 1, 2);

        rect = new QPushButton(gridLayoutWidget);
        rect->setObjectName("rect");
        rect->setFont(font);

        gridLayout->addWidget(rect, 6, 0, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimum(1);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(horizontalSlider, 10, 0, 1, 1);

        lineEdit_bsize = new QLineEdit(gridLayoutWidget);
        lineEdit_bsize->setObjectName("lineEdit_bsize");

        gridLayout->addWidget(lineEdit_bsize, 10, 1, 1, 1);

        save_col = new QPushButton(gridLayoutWidget);
        save_col->setObjectName("save_col");

        gridLayout->addWidget(save_col, 18, 0, 1, 2);

        col_prev = new QLabel(gridLayoutWidget);
        col_prev->setObjectName("col_prev");
        col_prev->setAutoFillBackground(false);

        gridLayout->addWidget(col_prev, 17, 1, 1, 1);

        dropper = new QPushButton(gridLayoutWidget);
        dropper->setObjectName("dropper");
        dropper->setFont(font);

        gridLayout->addWidget(dropper, 8, 1, 1, 1);

        fill = new QPushButton(gridLayoutWidget);
        fill->setObjectName("fill");
        fill->setFont(font);

        gridLayout->addWidget(fill, 8, 0, 1, 1);

        line = new QPushButton(gridLayoutWidget);
        line->setObjectName("line");
        line->setFont(font);

        gridLayout->addWidget(line, 7, 0, 1, 1);

        eraser = new QPushButton(gridLayoutWidget);
        eraser->setObjectName("eraser");
        eraser->setFont(font);

        gridLayout->addWidget(eraser, 5, 1, 1, 1);

        lasso = new QPushButton(gridLayoutWidget);
        lasso->setObjectName("lasso");
        lasso->setFont(font);

        gridLayout->addWidget(lasso, 6, 1, 1, 1);

        cur_tool = new QLabel(gridLayoutWidget);
        cur_tool->setObjectName("cur_tool");

        gridLayout->addWidget(cur_tool, 0, 0, 1, 2);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 2);

        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 839, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "HSV", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Brush Size", nullptr));
        col->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        brush->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        elipse->setText(QCoreApplication::translate("MainWindow", "Elipse", nullptr));
        rect->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        save_col->setText(QCoreApplication::translate("MainWindow", "Save current color", nullptr));
        col_prev->setText(QString());
        dropper->setText(QCoreApplication::translate("MainWindow", "Dropper", nullptr));
        fill->setText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        eraser->setText(QCoreApplication::translate("MainWindow", "Eraser", nullptr));
        lasso->setText(QCoreApplication::translate("MainWindow", "Lasso", nullptr));
        cur_tool->setText(QCoreApplication::translate("MainWindow", "Cur_tool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
