//
// Created by Alexandra on 6/22/2021.
//

#include "PersonWindow.h"

PersonWindow::PersonWindow(Service &service, Ethnologist &e, QWidget *parent):
service{service}, e{e} ,QWidget(parent)
{
    this->service.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

PersonWindow::~PersonWindow() {

}

void PersonWindow::update() {
    this->notifyModel();
}

void PersonWindow::notifyModel() {
    this->tableModel->updateInternalData();
}

void PersonWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->tableModel = new TableModel(this->service, this->e);
    this->buildingsTableView = new QTableView();
    this->buildingsTableView->setModel(this->tableModel);

    this->buildingsTableView->resizeColumnsToContents();

    this->descriptionLineEdit = new QLineEdit();
    this->descriptionLineEdit->setFont(buttonsFont);

    this->locationLineEdit = new QLineEdit();
    this->locationLineEdit->setFont(buttonsFont);

//    this->descriptionLineEdit2 = new QLineEdit();
//    this->descriptionLineEdit2->setFont(buttonsFont);
//
//    this->locationLineEdit2 = new QLineEdit();
//    this->locationLineEdit2->setFont(buttonsFont);

    QLabel* description = new QLabel("Description");
    description->setFont(buttonsFont);

    QLabel* location = new QLabel("Location");
    location->setFont(buttonsFont);

//    QLabel* description2 = new QLabel("Description");
//    description2->setFont(buttonsFont);
//
//    QLabel* location2 = new QLabel("Location");
//    location2->setFont(buttonsFont);


    this->addButton = new QPushButton("Add building!");
    this->addButton->setFont(buttonsFont);

    this->updateButton = new QPushButton("Update building!");
    this->updateButton->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout();
    this->mainLayout->addWidget(this->buildingsTableView);

    this->buttonsLayout = new QGridLayout();
    this->buttonsLayout->addWidget(description, 0, 0);
    this->buttonsLayout->addWidget(this->descriptionLineEdit, 0, 1);
    this->buttonsLayout->addWidget(location, 0, 2);
    this->buttonsLayout->addWidget(this->locationLineEdit, 0, 3);
    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addWidget(this->addButton);
    this->mainLayout->addWidget(this->updateButton);

    this->updateButton->setDisabled(true);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->e.getName()));
    this->resize(700,500);

    this->setAutoFillBackground(true);
    auto palette = this->palette();
    this->color = QColor(rand() % 256, rand() % 256, rand() % 256);
    palette.setColor(QPalette::Background, color);
    this->setPalette(palette);
}

void PersonWindow::connectSignals() {

    QObject::connect(this->addButton, &QPushButton::clicked, this, &PersonWindow::addBuilding);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &PersonWindow::updateBuilding);
    QObject::connect(this->buildingsTableView, &QTableView::clicked, this, &PersonWindow::check);
}

void PersonWindow::addBuilding() {
    string description = this->descriptionLineEdit->text().toStdString();
    string location = this->locationLineEdit->text().toStdString();
    string area = this->e.getArea();

    if(description.empty() || location.empty()) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        this->descriptionLineEdit->clear();
        this->locationLineEdit->clear();
        return;
    }

    try{
        this->service.addBuilding(description, area, location);
        QMessageBox::information(this, "OK", "Building added!");
        this->descriptionLineEdit->clear();
        this->locationLineEdit->clear();
    }
    catch(...){
        QMessageBox::critical(this, "Error", "Invalid input!");
        this->descriptionLineEdit->clear();
        this->locationLineEdit->clear();
        return;
    }
}

void PersonWindow::updateBuilding() {
    string description = this->descriptionLineEdit->text().toStdString();
    string location = this->locationLineEdit->text().toStdString();
    int index = this->getSelectedIndex();
    string id = this->service.getBuildingsByArea(this->e)[index].getID();
    if(description.empty() && location.empty()){
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try{
        this->service.updateBuilding(id, description, location);
        QMessageBox::information(this, "OK", "Building updated!");
        this->descriptionLineEdit->clear();
        this->locationLineEdit->clear();
    }
    catch(...){
        QMessageBox::critical(this, "Error", "Invalid input!");
        this->descriptionLineEdit->clear();
        this->locationLineEdit->clear();
        return;
    }

}

void PersonWindow::check() {
    int index = getSelectedIndex();
    Building b = this->service.getBuildingsByArea(this->e)[index];
    if(b.getArea() != this->e.getArea()){
        this->updateButton->setDisabled(true);
    }
    else{
        this->updateButton->setEnabled(true);
    }

}

int PersonWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->buildingsTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}
