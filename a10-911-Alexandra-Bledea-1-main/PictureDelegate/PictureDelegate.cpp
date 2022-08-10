//
// Created by Alexandra on 5/26/2021.
//

#include "PictureDelegate.h"
#include <QFont>
#include <QBrush>
#include "TableMode.h"
#include <QPixmap>
#include <QPainter>

PictureDelegate::PictureDelegate(QWidget *parent): QStyledItemDelegate{parent} {

}

void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QString coat = index.model()->data(index, Qt::EditRole).toString();

    if(index.column() != 1){
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    if(coat.contains("Blue")){
        QPixmap pixMap("blue.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Pink")){
        QPixmap pixMap("pink.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Red")){
        QPixmap pixMap("red.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Yellow")){
        QPixmap pixMap("yellow.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Orange")){
        QPixmap pixMap("orange.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Green")){
        QPixmap pixMap("green.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Grey")){
        QPixmap pixMap("grey.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Black")){
        QPixmap pixMap("black.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("White")){
        QPixmap pixMap("white.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Brown")){
        QPixmap pixMap("brown.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if(coat.contains("Purple")){
        QPixmap pixMap("purple.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else
    {
        QPixmap pixMap("rainbow.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if(index.column() == 1){
        return QSize(300,300);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}
