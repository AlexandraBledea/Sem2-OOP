//
// Created by Alexandra on 7/7/2021.
//

#include "Cells.h"
#include <time.h>
#include <fstream>

void Cells::LoadData() {
    ifstream inFile("input.txt");
    inFile >> this->sizeBoard;
    inFile >> this->nrMines;
    inFile.close();
}

Cells::Cells(): cells{vector<vector<Cell>>()} {
    this->LoadData();
    this->cells.resize(this->sizeBoard);
    for(int i = 0; i < this->sizeBoard; i++){
        for(int j = 0; j < this->sizeBoard; j++){
            this->cells[i].push_back(Cell());
        }
    }
    this->placeRandomMines();
}

Cells::~Cells() {

}

vector<vector<Cell>>& Cells::getAll() {
    return this->cells;
}

int Cells::getSize() {
    return this->sizeBoard;
}

int Cells::getNrMines() {
    return this->nrMines;
}

void Cells::placeRandomMines() {
    int count = 0;
    srand(time(NULL));
    while(count < this->nrMines) {
        int i = rand() % this->sizeBoard;
        int j = rand() % this->sizeBoard;
        if (this->cells[i][j].getText() != "*") {
            this->cells[i][j].setStatus(state::not_revealed);
            this->cells[i][j].setText("*");
            this->cells[i][j].setMine(true);
            count++;
        }
    }
}

void Cells::markMine(int i, int j) {
    if (checkRevealed(i, j)) {
        throw exception();
    } else {
        this->cells[i][j].setText("*");
        this->cells[i][j].setStatus(state::flagged);
        this->notify();
    }
}

bool Cells::checkRevealed(int i, int j) {
    return this->cells[i][j].getStatus() == state::revealed;
}

void Cells::revealCell(int i, int j) {
    if(this->cells[i][j].getText() == "*" && this->cells[i][j].getMine()){
        this->notify();
        throw exception();
    }
    else
    {
        int count = 0;
        if(i == 0 && j == 0){
            if(this->cells[i][j+1].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(i == 0 && j == this->sizeBoard-1){
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j-1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(i == this->sizeBoard - 1 && j == 0){
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i-1][j+1].getMine()){
                count++;
            }
            if(this->cells[i][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(i == this->sizeBoard - 1 && j == this->sizeBoard-1){
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i-1][j-1].getMine()){
                count++;
            }
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(i == 0 && j != 0 && j != this->sizeBoard - 1){
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            if(this->cells[i][j+1].getMine()){
                count++;
            }
            if(this->cells[i+1][j-1].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(j == 0 && i != 0 && i != this->sizeBoard-1){
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[j+1][j-1].getMine()){
                count++;
            }
            if(this->cells[j+1][i].getMine()){
                count++;
            }
            if(this->cells[j+1][i+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(i == this->sizeBoard - 1 && j != 0 && j != this->sizeBoard-1){
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            if(this->cells[i][j+1].getMine()){
                count++;
            }
            if(this->cells[i-1][j-1].getMine()){
                count++;
            }
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i-1][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
        else if(j == this->sizeBoard - 1 && i != 0 && i != this->sizeBoard - 1){
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[i-1][j-1].getMine()){
                count++;
            }
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            if(this->cells[i+1][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);

        }
        else
        {
            if(this->cells[i][j-1].getMine()){
                count++;
            }
            if(this->cells[i][j+1].getMine()){
                count++;
            }
            if(this->cells[i-1][j-1].getMine()){
                count++;
            }
            if(this->cells[i-1][j].getMine()){
                count++;
            }
            if(this->cells[i-1][j+1].getMine()){
                count++;
            }
            if(this->cells[i+1][j-1].getMine()){
                count++;
            }
            if(this->cells[i+1][j].getMine()){
                count++;
            }
            if(this->cells[i+1][j+1].getMine()){
                count++;
            }
            this->cells[i][j].setText(to_string(count));
            this->cells[i][j].setStatus(state::revealed);
        }
    this->notify();
    }
}
