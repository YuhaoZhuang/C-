//
// Created by mfbut on 2/24/2019.
//
#include "WindowImplementation.h"
#include <stdexcept>
/*
 * I've already added the cut to initialize curses if it hasn't been called
 * and to create the window. You may still need to do more initialization if
 * you have other members
 */
Curses::WindowImplementation::WindowImplementation(int numRows, int numCols, int startRow, int startCol) :
        cursesWindow(nullptr, delwin) {
    if (!stdscr) {
        initscr();
    }
    cursesWindow = std::unique_ptr<WINDOW, decltype(delwin)*>(newwin(numRows, numCols, startRow, startCol), delwin);
}

Curses::WindowImplementation::WindowImplementation(int numRows, int numCols) : WindowImplementation(numRows,
                                                                                                    numCols,
                                                                                                    0,
                                                                                                    0) {

}

//the unique pointer will automatically delete itself
//but if you dynamically allocate any more space for this
//problem make sure to free it here.
Curses::WindowImplementation::~WindowImplementation() {

}

char Curses::WindowImplementation::getWindowChar(int row, int col) {
    verifyInBounds(row,col);
    return (char)mvwinch(cursesWindow.get(), row, col);
}

char Curses::WindowImplementation::getWindowChar() {
    verifyInBounds(getCurRow(),getCurCol());
    return winch(cursesWindow.get());
}

char Curses::WindowImplementation::getCharInput(int row, int col) {
    verifyInBounds(row,col);
    return mvwgetch(cursesWindow.get(), row, col);
}

char Curses::WindowImplementation::getCharInput() {
    verifyInBounds(getCurRow(),getCurCol());
    return wgetch(cursesWindow.get());
}

std::string Curses::WindowImplementation::getStringInput(int row, int col) {
    verifyInBounds(row,col);
    char c;
    std::string str = "";
    c = getCharInput(row,col);
    while (c != '\n'){
        str = str+c;
        c = getCharInput(row,col);
    }
    if (!check) {
        wmove(cursesWindow.get(), row, col);
    }
    return str;
}

std::string Curses::WindowImplementation::getStringInput() {
    return getStringInput(getCurRow(),getCurCol());
}

void Curses::WindowImplementation::addCharacter(int row, int col, char value) {
    verifyInBounds(row,col);
    mvwaddch(cursesWindow.get(), row, col, value);
    if (!check) {
        wmove(cursesWindow.get(), row, col);
    }
}

void Curses::WindowImplementation::addCharacter(char value) {
    addCharacter(getCurRow(), getCurCol(), value);
}

void Curses::WindowImplementation::addString(int row, int col, const std::string& str) {
    verifyInBounds(row,col);
    mvwaddstr(cursesWindow.get(), row, col, str.c_str());
    if (!check) {

        int a = str.length()-1;
        int currow = row;
        int curcol = col;
        for (int i =0; i < a;i++){
            curcol +=1;
            if (curcol >= getNumCols()){
                curcol = 0;
                currow += 1;
            }
        }
        if (currow >= getNumRows()){
            wmove(cursesWindow.get(), getNumRows(),getNumCols());
        }

        wmove(cursesWindow.get(), currow, curcol);
    }

}

void Curses::WindowImplementation::addString(const std::string& str) {
    addString(getCurRow(), getCurCol(), str);
}

int Curses::WindowImplementation::getRowStart() const {
    return getbegy(cursesWindow.get());
}

int Curses::WindowImplementation::getColStart() const {
    return getbegx(cursesWindow.get());
}

int Curses::WindowImplementation::getNumRows() const {
    return getmaxy(cursesWindow.get());
}

int Curses::WindowImplementation::getNumCols() const {
    return getmaxx(cursesWindow.get());
}

int Curses::WindowImplementation::getCurRow() const {
    return getcury(cursesWindow.get());
}

int Curses::WindowImplementation::getCurCol() const {
    return getcurx(cursesWindow.get());
}

void Curses::WindowImplementation::moveCursor(int row, int col) {
    verifyInBounds(row,col);
    wmove(cursesWindow.get(), row, col);
}

void Curses::WindowImplementation::moveCursorLeft(int amount) {
    if (amount) {
        int total = 0;
        for (int i = 1; i <= amount; i++) {
            if (getCurCol() - i >= 0) {
                total += 1;
            }
        }
        moveCursor(getCurRow(), getCurCol() - total);
    }
    else {
        if (getCurCol() - 1 < 0) {
        }
        else {
            moveCursor(getCurRow(), getCurCol() - 1);
        }
    }
}

void Curses::WindowImplementation::moveCursorRight(int amount) {
    if (amount) {
        int total = 0;
        for (int i = 1; i <= amount; i++) {
            if (getCurCol() + i<getNumCols()) {
                total += 1;
            }
        }
        moveCursor(getCurRow(), getCurCol() + total);
    }
    else {
        if (getCurCol() + 1 > getNumCols()) {
        }
        else {
            moveCursor(getCurRow(), getCurCol() + 1);
        }

    }
}

void Curses::WindowImplementation::moveCursorUp(int amount) {
    if (amount) {
        int total = 0;
        for (int i = 1; i <= amount; i++) {
            if (getCurRow() - i >= 0) {
                total += 1;
            }
        }
        moveCursor(getCurRow() - total, getCurCol());
    }
    else {
        if (getCurRow() - 1< 0) {
        }
        else {
            moveCursor(getCurRow() - 1, getCurCol());
        }
    }
}

void Curses::WindowImplementation::moveCursorDown(int amount) {
    if (amount) {
        int total = 0;
        for (int i = 1; i <= amount; i++) {
            if (getCurRow() + i<getNumRows()) {
                total += 1;
            }
        }
        moveCursor(getCurRow() + total, getCurCol());
    }
    else {
        if (getCurRow() + 1 > getNumRows()) {
            moveCursor(getCurRow(), getCurCol());
        }
        else {
            moveCursor(getCurRow() + 1, getCurCol());
        }
    }
}

void Curses::WindowImplementation::setAdvanceCursorOn() {
    check = true;
}

void Curses::WindowImplementation::setAdvanceCursorOff() {
    check = false;
}

Curses::RowReference Curses::WindowImplementation::at(int row) {
    return RowReference(*this, row);
}

Curses::RowReference Curses::WindowImplementation::operator[](int row) {
    return RowReference(*this, row);
}

void Curses::WindowImplementation::refresh() {
    wrefresh(cursesWindow.get());
}

void Curses::WindowImplementation::log(std::ostream& out) {

    int a = getCurCol();
    int b = getCurRow();
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumCols(); j++) {
            out << getWindowChar(i, j);
        }
        out << std::endl;
    }
    moveCursor(b, a);

}


void Curses::Window::verifyInBounds(int row, int col) const {
    if (row >= getNumRows() || row < 0){
        throw std::out_of_range("out of range");
    }
    if (col >= getNumCols() || col<0){
        throw std::out_of_range("out of range");
    }
}

//return true if row,col is inside the window
bool Curses::Window::isInBounds(int row, int col) const {
    if (row < getNumRows() && col < getNumCols()){
        return true;
    }
    else{
        return false;
    }

}
//is val between low and high inclusive? low <= val <= high?
bool Curses::Window::isBetween(int val, int low, int high) const {
    if (low <= val && val <= high){
        return true;
    }
    else {
        return false;
    }
}