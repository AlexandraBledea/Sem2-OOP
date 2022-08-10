#include <iostream>
#include <QApplication>
#include "Cells.h"
#include "Players.h"
#include "PlayerWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    Players players;
    Cells cells;
    int turn = 0;
    vector<PlayerWindow*> windows;
    for(auto & p: players.getAll()){
        windows.push_back(new PlayerWindow(cells, p, turn, players));
    }

    return a.exec();
}
