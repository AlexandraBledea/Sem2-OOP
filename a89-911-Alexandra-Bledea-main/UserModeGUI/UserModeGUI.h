//
// Created by Alexandra on 4/29/2021.
//

#pragma once
#include "service.h"
#include <QVBoxLayout>
#include <qwidget.h>
#include <qlistwidget.h>
#include "AbstractShoppingBasket.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QDialog>

class UserModeGUI: public QDialog {

private:
    string size;
    int position;
    AbstractShoppingBasket* ASB;
    Service& service;
    QListWidget* coatsListWidget;
    QListWidget* shoppingBasketListWidget;
    QComboBox *sizeComboBox;
    QPushButton* displayProductsButton, * openApplicationButton, * displayShoppingBasketButton;
    QPushButton* nextButton, * buyButton, *payButton;

public:
    UserModeGUI(Service& service, AbstractShoppingBasket* ASB, QWidget* parent = NULL);
    ~UserModeGUI();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void initUserModeGUI();

    void connectSignalsAndSlotsDisplayFunction();

    void populateShoppingBag();

    void openApplication();

    void populateDisplayProducts(int position, vector<Coat> coats);
    void displayUserProducts();
    void nextProduct();
    void buyProduct();
    void initDisplayProducts();
    void displayProducts();
    void clearPopulatedList();

};


