//
// Created by Alexandra on 4/29/2021.
//

#include "AdminModeGUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include <qlabel.h>
#include <QMessageBox>
#include "validation.h"

AdminModeGUI::AdminModeGUI(Service &service, QWidget* parent): service{service}, QDialog{parent} {
    this->initAdminModeGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminModeGUI::initAdminModeGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->coatsListWidget = new QListWidget{};
    this->coatsListWidget->setFont(buttonsFont);

    this->sizeComboBox = new QComboBox{};
    this->sizeComboBox->setFont(buttonsFont);

    this->sizeComboBox->addItem("XXS");
    this->sizeComboBox->addItem("XS");
    this->sizeComboBox->addItem("S");
    this->sizeComboBox->addItem("M");
    this->sizeComboBox->addItem("L");
    this->sizeComboBox->addItem("XL");
    this->sizeComboBox->addItem("XXL");

    this->colorLineEdit = new QLineEdit{};
    this->colorLineEdit->setFont(buttonsFont);

    this->priceLineEdit = new QLineEdit{};
    this->priceLineEdit->setFont(buttonsFont);

    this->quantityLineEdit = new QLineEdit{};
    this->quantityLineEdit->setFont(buttonsFont);

    this->photographLineEdit = new QLineEdit{};
    this->photographLineEdit->setFont(buttonsFont);

    this->undoButton = new QPushButton{"Undo"};
    this->undoButton->setFont(buttonsFont);

    this->redoButton = new QPushButton{"Redo"};
    this->redoButton->setFont(buttonsFont);

    this->addButton = new QPushButton{"Add"};
    this->addButton->setFont(buttonsFont);

    this->deleteSoldOutButton = new QPushButton{"Delete SoldOut"};
    this->deleteSoldOutButton->setFont(buttonsFont);

    this->deleteButton = new QPushButton{"Delete"};
    this->deleteButton->setFont(buttonsFont);

    this->updatePriceButton = new QPushButton{"Update Price"};
    this->updatePriceButton->setFont(buttonsFont);

    this->updateQuantityButton = new QPushButton{"Update Quantity"};
    this->updateQuantityButton->setFont(buttonsFont);

    this->displayButton = new QPushButton{"Display"};
    this->displayButton->setFont(buttonsFont);

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *coatsText = new QLabel();
    coatsText->setText("The list of coats");
    QFont coatsFont("Consolas", 15, true);
    coatsText->setFont(coatsFont);

    QLabel *size = new QLabel();
    size->setText("Size");
    size->setFont(buttonsFont);

    QLabel *color = new QLabel();
    color->setText("Color");
    color->setFont(buttonsFont);

    QLabel *price = new QLabel();
    price->setText("Price");
    price->setFont(buttonsFont);

    QLabel *quantity = new QLabel();
    quantity->setText("Quantity");
    quantity->setFont(buttonsFont);

    QLabel *photograph = new QLabel();
    photograph->setText("Photograph");
    photograph->setFont(buttonsFont);

    QVBoxLayout* adminLayout = new QVBoxLayout();
    adminLayout->addWidget(coatsText);
    adminLayout->addWidget(this->coatsListWidget);

    QFormLayout* coatDetails = new QFormLayout();
    coatDetails->addRow(size, this->sizeComboBox);
    coatDetails->addRow(color, this->colorLineEdit);
    coatDetails->addRow(price, this->priceLineEdit);
    coatDetails->addRow(quantity, this->quantityLineEdit);
    coatDetails->addRow(photograph, this->photographLineEdit);

    adminLayout->addLayout(coatDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->deleteSoldOutButton, 0, 2);
    buttonsLayout->addWidget(this->updatePriceButton, 1, 0);
    buttonsLayout->addWidget(this->updateQuantityButton, 1, 1);
    buttonsLayout->addWidget(this->displayButton, 1, 2);
    buttonsLayout->addWidget(this->undoButton, 2, 0);
    buttonsLayout->addWidget(this->redoButton, 2, 1);

    adminLayout->addLayout(buttonsLayout);

    QWidget *adminDisplayWindow = new QWidget();
    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z), adminDisplayWindow);

    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y), adminDisplayWindow);

    adminDisplayWindow->setLayout(adminLayout);
    adminDisplayWindow->show();
}

void AdminModeGUI::populateList() {
    this->coatsListWidget->clear();
    vector<Coat> Coats = this->service.GetRepository();
    for (Coat &c: Coats) {
        this->coatsListWidget->addItem(QString::fromStdString(c.GetSize() + " - " + c.GetColor() + " - " + to_string(c.GetPrice()) + " - " + to_string(c.GetQuantity())
        + " - " + c.GetPhotograph()));

    }
}

void AdminModeGUI::connectSignalsAndSlots() {
    QObject::connect(this->coatsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();

        if(selectedIndex < 0)
            return;

        Coat c = this->service.GetRepository()[selectedIndex];
        this->sizeComboBox->setCurrentText(QString::fromStdString(c.GetSize()));
        this->colorLineEdit->setText(QString::fromStdString(c.GetColor()));
        this->priceLineEdit->setText(QString::fromStdString(to_string(c.GetPrice())));
        this->quantityLineEdit->setText(QString::fromStdString(to_string(c.GetQuantity())));
        this->photographLineEdit->setText(QString::fromStdString(c.GetPhotograph()));
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminModeGUI::addCoat);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminModeGUI::deleteCoat);
    QObject::connect(this->deleteSoldOutButton, &QPushButton::clicked, this, &AdminModeGUI::deleteSoldOutCoat);
    QObject::connect(this->updatePriceButton, &QPushButton::clicked, this, &AdminModeGUI::updatePriceCoat);
    QObject::connect(this->updateQuantityButton, &QPushButton::clicked, this, &AdminModeGUI::updateQuantityCoat);
    QObject::connect(this->displayButton, &QPushButton::clicked, this, &AdminModeGUI::populateList);
    QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminModeGUI::undo);
    QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminModeGUI::redo);
    QObject::connect(this->undoShortcut, &QShortcut::activated, this, &AdminModeGUI::undo);
    QObject::connect(this->redoShortcut, &QShortcut::activated, this, &AdminModeGUI::redo);
}

int AdminModeGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
    {
        this->colorLineEdit->clear();
        this->priceLineEdit->clear();
        this->quantityLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdminModeGUI::addCoat()
{
    string size = this->sizeComboBox->currentText().toStdString();
    string color = this->colorLineEdit->text().toStdString();
    string price = this->priceLineEdit->text().toStdString();
    string quantity = this->quantityLineEdit->text().toStdString();
    string photograph = this->photographLineEdit->text().toStdString();

    int validate_price = Validator::validate_price_product(price);
    int validate_quantity = Validator::validate_quantity_product(quantity);


    if(!Validator::validate_color_product(color) || validate_price == -1
       || validate_quantity == -1 || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.AddService(size, color, stoi(price), stoi(quantity), photograph);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't add the product!");
            return;
        }
    }
    this->populateList();

    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);
}

void AdminModeGUI::deleteCoat() {
    string size = this->sizeComboBox->currentText().toStdString();
    string color = this->colorLineEdit->text().toStdString();
    string photograph = this->photographLineEdit->text().toStdString();
    if(!Validator::validate_color_product(color) || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.DeleteService(size, color, photograph, 1);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);

}

void AdminModeGUI::deleteSoldOutCoat() {
    string size = this->sizeComboBox->currentText().toStdString();
    string color = this->colorLineEdit->text().toStdString();
    string photograph = this->photographLineEdit->text().toStdString();
    if(!Validator::validate_color_product(color) || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.DeleteService(size, color, photograph, 2);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);


}

void AdminModeGUI::updatePriceCoat() {
    string size = this->sizeComboBox->currentText().toStdString();
    string color = this->colorLineEdit->text().toStdString();
    string photograph = this->photographLineEdit->text().toStdString();
    string price = this->priceLineEdit->text().toStdString();
    int validate_price = Validator::validate_price_product(price);

    if(!Validator::validate_color_product(color) || validate_price == -1
       || !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.UpdatePriceService(size, color, photograph, stoi(price));
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't update the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);

}

void AdminModeGUI::updateQuantityCoat() {
    string size = this->sizeComboBox->currentText().toStdString();
    string color = this->colorLineEdit->text().toStdString();
    string photograph = this->photographLineEdit->text().toStdString();
    string quantity = this->quantityLineEdit->text().toStdString();
    int validate_quantity = Validator::validate_quantity_product(quantity);
    if(!Validator::validate_color_product(color) || validate_quantity == -1 ||
    !Validator::validate_photograph_product(photograph))
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    else
    {
        try{
            this->service.UpdateQuantityService(size, color, photograph, stoi(quantity));;
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't update the product!");
            return;
        }
    }
    this->populateList();
    int lastElement = this->service.GetRepository().size()-1;
    this->coatsListWidget->setCurrentRow(lastElement);
}

AdminModeGUI::~AdminModeGUI() {

}

void AdminModeGUI::undo() {
    try{
        this->service.undoAdminMode();
        this->populateList();
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "There are no more undos");
        return;
    }
}

void AdminModeGUI::redo() {

    try{
        this->service.redoAdminMode();
        this->populateList();
    }
    catch(...){
        QMessageBox::critical(this, "Error", "There are no more redos!");
        return;
    }

}
