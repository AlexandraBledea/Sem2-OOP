//
// Created by Alexandra on 6/16/2021.
//

#include "TableModel.h"
#include <QFont>
#include <QBrush>

TableModel::TableModel(Service& service, Ethnologist& e, QObject *parent): service{service}, e{e},  QAbstractTableModel{parent} {

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->service.getBuildingsByArea(e).size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Building> buildings = this->service.getBuildingsByArea(this->e);
        Building f = buildings[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(f.getID());

            case 1:
                return QString::fromStdString(f.getDescription());

            case 2:
                return QString::fromStdString(f.getArea());

            case 3: {
                string loc;
                for (auto &l: f.getLocation()) {
                    loc += " " + l;
                }
                return QString::fromStdString(loc);
            }
            default:
                break;

        }
    }

    vector<Building> buildings = this->service.getBuildingsByArea(e);

    if(role == Qt::FontRole){
            QFont font("Times", 15, 10, true);
            font.setItalic(false);
            return font;
    }

    if(role == Qt::BackgroundRole){
        if(buildings[row].getArea() == e.getArea()){
            return QBrush{Qt::blue};
        }
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"ID"};

                case 1:
                    return QString{"Description"};

                case 2:
                    return QString{"Thematic area"};

                case 3:
                    return QString{"Location"};

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModel::updateInternalData() {
    beginResetModel();
    endResetModel();
}
