//
// Created by mfbut on 2/22/2019.
//

#include "RowReference.h"


class RowReference;
class CellReference;
Curses::RowReference::RowReference(Window& win, const int row): win(win), row(row) {}
Curses::CellReference Curses::RowReference::at(int col) {

    return CellReference(win, row, col);
}
Curses::CellReference Curses :: RowReference::operator[](int col) {
    return CellReference(win, row, col);
}
