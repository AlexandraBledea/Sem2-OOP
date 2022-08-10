//
// Created by Alexandra on 7/7/2021.
//

#include <QFont>
#include "TableModel.h"
#include <QBrush>

TableModel::TableModel(Cells &repository, QObject *parent): repository{repository}, QAbstractTableModel(parent)  {

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return repository.getSize();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return repository.getSize();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<vector<Cell>> cells = this->repository.getAll();
        Cell c = cells[row][column];
        if(c.getStatus() == state::revealed){
            return QString::fromStdString(c.getText());
        }
        else if(c.getStatus() == state::flagged){
            return QString::fromStdString(c.getText());
        }
        return QVariant();
    }

    vector<vector<Cell>> cells = this->repository.getAll();
    Cell c = cells[row][column];

    if(role == Qt::FontRole){
            QFont font("Times", 15, 10, true);
            font.setItalic(false);
            return font;
    }

    if(role == Qt::BackgroundRole){
        if(c.getStatus() == state::revealed){
            return QBrush{QColor{Qt::blue}};
        }
        else if(c.getStatus() == state::flagged){
            return QBrush{QColor{Qt::red}};
        }
        else if(c.getStatus() == state::not_revealed){
            return QBrush{QColor{Qt::green}};
        }
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            char letter = 'A';
            letter+=section;
            string str = {letter};
            return QString::fromStdString(str);
        }
        else if( orientation == Qt::Vertical){
            return QString::number(section);
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
    endResetModel();
}
