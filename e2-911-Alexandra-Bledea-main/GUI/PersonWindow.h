//
// Created by Alexandra on 6/22/2021.
//

#pragma once
#pragma "Observer.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModel.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include "Service.h"
#include "Ethnologist.h"
#include  <QMessageBox>

class PersonWindow: public Observer, public QWidget{

private:
    Service& service;
    Ethnologist& e;
    TableModel* tableModel;
    QTableView* buildingsTableView;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QLineEdit* descriptionLineEdit, *locationLineEdit;
    QLineEdit* descriptionLineEdit2, *locationLineEdit2;
    QPushButton* addButton, *updateButton;
    QColor color;

public:

    PersonWindow(Service& service, Ethnologist& e, QWidget*parent = Q_NULLPTR);
    ~PersonWindow();
    void update() override;
    void notifyModel();
    void initGUI();
    void connectSignals();
    void addBuilding();
    void updateBuilding();
    void check();
    int getSelectedIndex();

};
