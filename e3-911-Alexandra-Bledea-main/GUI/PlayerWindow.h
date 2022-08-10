//
// Created by Alexandra on 7/7/2021.
//

#pragma once
#include "Observer.h"
#include <QWidget>
#include "Cells.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModel.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include "Person.h"
#include "Players.h"

class PlayerWindow: public Observer, public QWidget{

private:
    QPushButton* revealButton, *mineButton;
    QLineEdit* coordsLineEdit;
    QTableView* gameTableView;
    TableModel* tableModel;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    Cells& cells;
    int& turn;
    Players& players;
    Person& p;

public:
    PlayerWindow(Cells& cells, Person& p, int& turn, Players& players);
    ~PlayerWindow();
    void initGUI();
    void connectSignals();
    void update() override;
    void notifyModel();
    void markMine();
    void revealCell();
};
