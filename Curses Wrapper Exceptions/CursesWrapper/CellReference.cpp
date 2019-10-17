//
// Created by mfbut on 2/24/2019.
//

#include "CellReference.h"
#include "WindowImplementation.h"


Curses::CellReference::CellReference(Window& win, const int row, const int col): win(win), row(row), col(col) {}
Curses::CellReference& Curses::CellReference::operator=(const char letter) {

    win.addCharacter(row, col, letter);
    win.moveCursor(row, col);
    return *this;
}

Curses::CellReference::operator char()const {
    return win.getWindowChar(row, col);
}


