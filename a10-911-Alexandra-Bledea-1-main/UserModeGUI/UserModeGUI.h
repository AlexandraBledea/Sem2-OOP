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
#include "TableMode.h"
#include <QTableView>

class UserModeGUI: public QDialog {

private:
    string size;
    int position;
    AbstractShoppingBasket* ASB;
    Repository& repository;
    Service& service;
    QListWidget* coatsListWidget;
    QListWidget* shoppingBasketListWidget;
    QComboBox *sizeComboBox;
    QPushButton* displayProductsButton, * openApplicationButton, * displayShoppingBasketButton, *undoButton, *redoButton;
    QPushButton* nextButton, * buyButton, *payButton;
    QPushButton* tableButton;

    QTableView* shoppingBasketTableView;
    TableMode* tableMode;

    int columnCount = 4;
    int rowCount = 0;

public:
    UserModeGUI(Service& service, Repository& repository, AbstractShoppingBasket* ASB, QWidget* parent = NULL);
    ~UserModeGUI();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void initUserModeGUI();

    void connectSignalsAndSlotsDisplayFunction();

    void populateShoppingBag();

    void openApplication();

    void openTableView();

    void notifyModel();

    void populateDisplayProducts(int position, vector<Coat> coats);
    void displayUserProducts();
    void nextProduct();
    void buyProduct();
    void initDisplayProducts();
    void displayProducts();
    void clearPopulatedList();

    void undo();
    void redo();


};


