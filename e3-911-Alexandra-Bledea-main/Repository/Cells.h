//
// Created by Alexandra on 7/7/2021.
//

#pragma once
#include <string>
using namespace std;
#include <vector>
#include "Cell.h"
#include "Observer.h"

class Cells: public Observable{

private:
    vector<vector<Cell>> cells;
    int sizeBoard;
    int nrMines;
    void LoadData();

public:
    Cells();
    ~Cells();
    vector<vector<Cell>>& getAll();
    int getSize();
    int getNrMines();
    void placeRandomMines();
    void markMine(int i , int j);
    bool checkRevealed(int i, int j);
    void revealCell(int i, int j);

};
