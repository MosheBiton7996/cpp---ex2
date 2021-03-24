#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

namespace ariel
{
    const unsigned int initBoard = 10;
    Board::Board()
    {
        sumRows = sumCols = initBoard;
        firstRow = firstCol = UINT_MAX;
        board = vector<vector<char>>(sumRows, vector<char>(sumCols, '_'));
    }
	
    void Board::post(unsigned int row, unsigned int col, Direction direction, string val)
    {
        unsigned int length = val.length();
        if (direction == Direction::Horizontal)
        {
            col = col > (UINT_MAX - length) ? 0 : col;
            row = (row == UINT_MAX) ? 0 : row;
        }
        else
        {
            row = row > (UINT_MAX - length) ? 0 : row;
            col = (col == UINT_MAX) ? 0 : col;
        }

        firstRow = min(firstRow, row);
        firstCol = min(firstCol, col);

        resizeBoard(row, col, length, direction);

        for (size_t i = 0; i < val.length(); i++)
        {
            board[row][col] = val.at(i); 
            direction == Direction::Vertical ? row++ : col++;
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
    {
        string output;

        for (size_t i = 0; i < length; i++)
        {
            if (col == UINT_MAX || row == UINT_MAX)
            {
                while (i < length)
                {
                    output += '_';
                    i++;
                }
                return output;
            }
            if (row >= sumRows || col >= sumCols)
            {
                output += '_';
            }
            else
            {
                output += board[row][col];
            }
            direction == Direction::Vertical ? row++ : col++;
        }
        return output;
    }

void Board::show()
    {
    
    }
    void Board::resizeBoard(unsigned int row, unsigned int col, unsigned int length, Direction direction)
    {
        if (direction == Direction::Vertical)
        {
            sumRows = max(sumRows, row + length);
            sumCols = max(sumCols, col + 1);
        }
        else
        {
            sumCols = max(sumCols, col + length);
            sumRows = max(sumRows, row + 1);
        }
        board.resize(sumRows);
        for (size_t i = 0; i < sumRows; i++)
        {
            board[i].resize(sumCols, '_');
        }
    }
}
