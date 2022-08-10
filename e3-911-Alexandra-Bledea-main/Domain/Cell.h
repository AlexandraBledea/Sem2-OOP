//
// Created by Alexandra on 7/7/2021.
//

#pragma once
#include <string>
using namespace std;
enum state{
    revealed,
    not_revealed,
    flagged,
    };


class Cell {

private:
    state status;
    string text;
    bool mine;

public:
    Cell(state status, string text, bool mine);
    Cell();
    ~Cell();
    void setStatus(state status);
    void setText(string text);
    void setMine(bool mine);
    bool getMine();
    state getStatus();
    string getText();

};
