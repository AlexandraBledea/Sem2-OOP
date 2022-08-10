
#include "service.h"
#include "validation.h"
#include "AbstractShoppingBasket.h"
#include <QVBoxLayout>
#include "AdminModeGUI.h"
#include "UserModeGUI.h"
#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QMainWindow>

class GUI: public QMainWindow
{
    Q_OBJECT
private:
    string type = "empty";
    Service& service;
    Repository& repository;
    AbstractShoppingBasket* ASB;
    void initGUI();
    ///Graphical elements
    QComboBox *filetypeComboBox;
    QPushButton* adminModeButton, * userModeButton, *saveButton, *openChart;

public:
    GUI(Service& service, Repository& repository, QWidget *parent = 0);
    ~GUI();
    void connectSignalsAndSlots();
    void startUserModeGUI();
    void startAdminModeGUI();
    void saveFileType();
    void createChart();

};

