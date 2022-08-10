

#include "GUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include "qlabel.h"
#include <iostream>
#include <QMessageBox>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>

using namespace std;
GUI::GUI(Service &service, Repository& repository, QWidget* parent): repository{repository}, service{service}, QMainWindow(parent)
{
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {

    QFont buttonsFont("Consolas", 13, true);

    this->saveButton = new QPushButton{"Save File Type"};
    this->saveButton->setFont(buttonsFont);

    this->adminModeButton = new QPushButton{"Admin Mode"};
    this->adminModeButton->setFont(buttonsFont);

    this->userModeButton = new QPushButton{"User Mode"};
    this->userModeButton->setFont(buttonsFont);

    this->openChart = new QPushButton{"Open Chart"};
    this->openChart->setFont(buttonsFont);

    this->filetypeComboBox = new QComboBox{};
    this->filetypeComboBox->setFont(buttonsFont);
    this->filetypeComboBox->addItem("CSV File");
    this->filetypeComboBox->addItem("HTML File");

    QVBoxLayout* mainLayout = new QVBoxLayout();

    QLabel *introduction = new QLabel();
    introduction->setText("☺ WELCOME TO THE TRENCH COATS SHOP ☺");
    introduction->setAlignment(Qt::AlignCenter);
    QFont introduction_font("Consolas", 20, true, true);
    introduction->setFont(introduction_font);

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *filename = new QLabel();
    filename->setText("Choose the type of the file");
    QFont font_filename("Consolas", 15, true);
    filename->setFont(font_filename);

    mainLayout->addWidget(introduction);
    mainLayout->addWidget(space);
    mainLayout->addWidget(space);

    QFormLayout* fileDetails = new QFormLayout();
    fileDetails->addRow(filename, this->filetypeComboBox);

    mainLayout->addLayout(fileDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->saveButton, 0, 0);
    buttonsLayout->addWidget(this->userModeButton, 1, 0);
    buttonsLayout->addWidget(this->adminModeButton, 2, 0);
    buttonsLayout->addWidget(this->openChart, 3, 0);

    mainLayout->addLayout(buttonsLayout);

    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);


}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveFileType);
    QObject::connect(this->userModeButton, &QPushButton::clicked, this, &GUI::startUserModeGUI);
    QObject::connect(this->adminModeButton, &QPushButton::clicked, this, &GUI::startAdminModeGUI);;
    QObject::connect(this->openChart, &QPushButton::clicked, this, &GUI::createChart);
}

void GUI::startUserModeGUI() {
    if(type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    }
    else {
        this->setCursor(Qt::WaitCursor);
        UserModeGUI* umg = new UserModeGUI{this->service, this->repository, this->ASB};
//        umg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::startAdminModeGUI() {
    if (type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    } else {
        this->setCursor(Qt::WaitCursor);
        AdminModeGUI* amg = new AdminModeGUI{service};
//        amg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::saveFileType() {
    this->type= this->filetypeComboBox->currentText().toStdString();
    if(this->type == "CSV File")
        this->ASB = new CSVShoppingBasket();
    else if(this->type == "HTML File")
        this->ASB = new HTMLShoppingBasket();
}

GUI::~GUI() {

}

void GUI::createChart() {

    QFont legendFond("Consolas", 13, true);

    QtCharts::QBarSeries *Bars = new QtCharts::QBarSeries();
    for(auto c: this->service.GetRepository())
    {
        auto* set = new QtCharts::QBarSet(QString::fromStdString(c.GetColor()));
        *set << c.GetQuantity();
        Bars->append(set);
    }

    QtCharts::QChart *Chart = new QtCharts::QChart{};
    Chart->addSeries(Bars);
    Chart->setTitle("Coats displayed by color and quantity");
    Chart->setTitleFont(legendFond);
    Chart->setTheme(QChart::ChartThemeQt);

    Chart->setAnimationOptions(QtCharts::QChart::AllAnimations);
    Chart->setAnimationDuration(2000);

    Chart->createDefaultAxes();

    Chart->legend()->setVisible(true);
    Chart->legend()->setAlignment(Qt::AlignBottom);
    Chart->legend()->setFont(legendFond);

    QtCharts::QChartView *ChartView = new QtCharts::QChartView(Chart);

    ChartView->setRenderHint(QPainter::SmoothPixmapTransform);
    ChartView->resize(1200, 800);
    ChartView->show();
}












//    QWidget* chartWindow = new QWidget{};
//    QHBoxLayout* chartLayout = new QHBoxLayout{chartWindow};
//
//    int x = (int)(chartWindow->width() * 10);
//    int y = (int)(chartWindow->height() * 10);
//
//    chartWindow->resize(x, y);
//    QtCharts::QBarCategoryAxis *BarAxis = new QtCharts::QBarCategoryAxis();
//    Chart->setAxisX(BarAxis, Bars);