//
// Created by Alexandra on 5/21/2021.
//

#include <QFont>
#include <QBrush>
#include "TableMode.h"
#include <QPixmap>
#include <QPainter>

TableMode::TableMode(Repository &repository, QObject *parent): repository{repository}, QAbstractTableModel{parent}{
    this->coatsCount = this->repository.GetDynArr().size();
}

TableMode::~TableMode() {

}

int TableMode::rowCount(const QModelIndex &parent) const {
    int coatsNumber = this->repository.GetSize();
    return coatsNumber;
//    return coatsNumber + 1;
}

int TableMode::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableMode::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

//    vector<Coat> coats = this->repository.GetDynArr();

    /// Allow adding in the table
    /// this is to show an empty row at the end of the table - to allow adding new coats
//    if(row == coats.size())
//    {
//        return QVariant();
//    }

    ///Get the coat from the current row
//    Coat c = coats[row];

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Coat> coats = this->repository.GetDynArr();
        Coat c = coats[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(c.GetSize());

            case 1:
                return QString::fromStdString(c.GetColor());

            case 2:
                return QString::fromStdString(to_string(c.GetPrice()));

            case 3:
                return QString::fromStdString(to_string(c.GetQuantity()));

            case 4:
                return QString::fromStdString(c.GetPhotograph());

            default:
                break;

        }
    }

    if(role == Qt::FontRole){

        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
//    if(role == Qt::BackgroundRole)
//    {
//        if(row % 2 == 1){
//            return QBrush{ QColor{0, 250, 154} };
//        }
//    }

    return QVariant{};

};

QVariant TableMode::headerData(int section, Qt::Orientation orientation, int role) const {

    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"Size"};

                case 1:
                    return QString{"Color"};

                case 2:
                    return QString{"Price"};

                case 3:
                    return QString{"Quantity"};

                case 4:
                    return QString{"Photograph"};

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
//
//bool TableMode::setData(const QModelIndex &index, const QVariant &value, int role) {
//
//    if(!index.isValid() || role != Qt::EditRole)
//        return false;
//
//    int coatIndex = index.row();
//
//    vector<Coat> coats = this->repository.GetDynArr();
//
//    if(coatIndex == coats.size()){
//        this->beginInsertRows(QModelIndex{}, coatIndex, coatIndex);
//
//        switch(index.column()){
//            case 0:
//                this->repository.AddRepo(Coat{ value.toString().toStdString(), "", 0, 0, ""});
//                break;
//
//            case 1:
//                this->repository.AddRepo(Coat{"", value.toString().toStdString(), 0, 0, ""});
//                break;
//
//            case 2:
//                this->repository.AddRepo(Coat{"", "", stoi(value.toString().toStdString()), 0, "" });
//                break;
//
//            case 3:
//                this->repository.AddRepo(Coat{"", "", 0, stoi(value.toString().toStdString()), ""});
//                break;
//
//            case 4:
//                this->repository.AddRepo(Coat{"", "", 0, 0, value.toString().toStdString()});
//                break;
//        }
//        this->endInsertRows();
//        return true;
//    }
//
//    Coat coat = coats[coatIndex];
//
//    switch(index.column())
//    {
//        case 2:
//            coat.SetPrice(stoi(value.toString().toStdString()));
//
//        case 3:
//            coat.SetQuantity(stoi(value.toString().toStdString()));
//
//    }
//
//    this->repository.UpdateCoatRepo(coat, coatIndex);
//
//    emit dataChanged(index, index);
//
//    return true;
//}

Qt::ItemFlags TableMode::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableMode::updateInternalData() {
//    this->coatsCount = this->repository.GetDynArr().size();
    endResetModel();

}

//void TableMode::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
//    QString coat = index.model()->data(index, Qt::EditRole).toString();
//
//    if(index.column() != 4){
//        QStyledItemDelegate::paint(painter, option, index);
//        return;
//    }
//
//    if(coat.contains("Blue")){
//        QPixmap pixMap(R"(C:/Users/Alexandra/Desktop/Facultate/Semestru 2/911/a89-911-Alexandra-Bledea/blue.jpg)");
//        painter->drawPixmap(option.rect, pixMap);
//    }
//}
//
//QSize TableMode::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
//    if(index.column() == 1){
//        return QSize(32,100);
//    }
//    return QStyledItemDelegate::sizeHint(option, index);
//}

