//
// Created by Alexandra on 7/7/2021.
//

#include <QMessageBox>
#include "PlayerWindow.h"

PlayerWindow::PlayerWindow(Cells &cells, Person &p, int& turn, Players& players): cells{cells}, p{p}, turn{turn}, players{players} {
    this->cells.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();

}

PlayerWindow::~PlayerWindow() {

}

void PlayerWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->tableModel = new TableModel(this->cells);
    this->gameTableView = new QTableView();
    this->gameTableView->setModel(this->tableModel);
    this->gameTableView->resizeColumnsToContents();

    this->revealButton = new QPushButton("Reveal");
    this->revealButton->setFont(buttonsFont);

    this->mineButton = new QPushButton("Mark mine");
    this->mineButton->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout();
    this->buttonsLayout = new QGridLayout();

    QLabel* coordinates = new QLabel("Coordinates");
    coordinates->setFont(buttonsFont);

    this->coordsLineEdit = new QLineEdit();
    this->coordsLineEdit->setFont(buttonsFont);

    this->mainLayout->addWidget(this->gameTableView);
    this->buttonsLayout->addWidget(coordinates, 0, 0);
    this->buttonsLayout->addWidget(this->coordsLineEdit, 0, 1);
    this->buttonsLayout->addWidget(this->revealButton, 1, 0);
    this->buttonsLayout->addWidget(this->mineButton, 1, 1);

    this->mainLayout->addLayout(this->buttonsLayout);

    Person per = this->players.getAll()[turn];
    if(per.getName() != this->p.getName()){
        this->revealButton->setDisabled(true);
        this->mineButton->setDisabled(true);
    }

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->p.getName()));
    this->resize(700,500);
}

void PlayerWindow::connectSignals() {
    QObject::connect(this->mineButton, &QPushButton::clicked, this, &PlayerWindow::markMine);
    QObject::connect(this->revealButton, &QPushButton::clicked, this, &PlayerWindow::revealCell);
}

void PlayerWindow::update() {
    Person per = this->players.getAll()[this->turn];
    if(per.getName() != this->p.getName()){
        this->revealButton->setDisabled(true);
        this->mineButton->setDisabled(true);
    }
    else if(per.getName() == this->p.getName()){
        this->revealButton->setEnabled(true);
        this->mineButton->setEnabled(true);
    }
    this->notifyModel();
}

void PlayerWindow::notifyModel() {
    this->tableModel->updateInternalData();
}

void PlayerWindow::markMine() {
    string coords = this->coordsLineEdit->text().toStdString();
    int pos1 = coords[0] - 'A';
    int pos2 = coords[1] - '0';
    if(pos1 > this->cells.getSize() || pos1 < 0 || pos2 > this->cells.getSize() || pos2 < 0){
        QMessageBox::critical(this, "Error", "Invalid coordinates!");
        return;
    }
    else{
        try{
            this->turn+=1;
            if(turn == this->players.getAll().size())
                this->turn = 0;
            this->cells.markMine(pos2, pos1);
        }
        catch(...){
            QMessageBox::critical(this, "Error", "Invalid coordinates!");
            this->turn-=1;
            return;
        }
    };
}

void PlayerWindow::revealCell() {
    string coords = this->coordsLineEdit->text().toStdString();
    int pos1 = coords[0] - 'A';
    int pos2 = coords[1] - '0';
    if(pos1 > this->cells.getSize() || pos1 < 0 || pos2 > this->cells.getSize() || pos2 < 0){
        QMessageBox::critical(this, "Error", "Invalid coordinates!");
        return;
    }
    else
    {
        try{
            if(this->cells.checkRevealed(pos2, pos1))
                throw exception();
        }
        catch(...){
            QMessageBox::critical(this, "Error", "Invalid coordinates!");
            return;
        }

        try{
            this->turn+=1;
            if(turn == this->players.getAll().size())
                this->turn = 0;
            this->cells.revealCell(pos2, pos1);
        }
        catch(...){
            QMessageBox::critical(this, "Error", "Game over!");
            this->hide();
            this->players.getAll().erase(this->players.getAll().begin() + this->turn);
            if(turn == this->players.getAll().size())
                this->turn = 0;
            this->update();
            return;
        }
    }
}
