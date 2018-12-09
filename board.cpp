#include "board.h"

Board::Board()
{
    for (int i = 0; i < 16; i++)
    {
        boardRows.push_back(BoardRow());
    }
}

int &Board::getCondition(int col, int row)
{
    return this->boardRows.at(col).getCellConditions().at(row);
}

void Board::print()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << this->getCondition(i, j);
        }
        cout<<"\n";
    }
}

vector<BoardRow> Board::getBoardRows()
{
    return this->boardRows;
}

BoardRow::BoardRow()
{
    for (int i = 0; i < 16; i++)
    {
        cellConditions.push_back(0);
    }
}

vector<int> &BoardRow::getCellConditions()
{
    return this->cellConditions;
}
