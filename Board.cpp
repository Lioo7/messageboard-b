#include "Board.hpp"
#include <iostream>
#include <climits>

using namespace std;
const char blank_cell = '_';
uint min_row = UINT_MAX;
uint max_row = 1;
uint min_col = UINT_MAX;
uint max_col = 1;

namespace ariel
{
    // This function increase the size of the board
    void Board::boardResize(uint row, uint col)
    {
        max_row = max(max_row, row);
        max_col = max(max_col, col);

        this->rows = max_row + 1;
        this->columns = max_col + 1;
        this->board.resize(rows); // increases the rows

        for (uint i = 0; i < rows; i++)
        {
            // increases the columns of each row and initialize with blank cell
            board[i].resize(columns, blank_cell);
        }
    }

    // This function post a new post in the board
    void Board::post(uint row, uint col, Direction direction, string text)
    {
        min_row = min(min_row, row);
        min_col = min(min_col, col);

        uint length = text.length();
        if(length > 0) empty = false;

        if (direction == Direction::Horizontal)
        {
            if ((col + length > max_col) || row > max_row)
            {
                boardResize(row, col + length);
                // cout << board.size() << endl;
                // cout << board[1].size() << endl;
            }
            for (uint i = 0; i < length; i++)
            {
                this->board[row][col + i] = text[i];
            }
        }

        else
        {
            if ((col > max_col) || row + length > max_row)
            {
                boardResize(row + length, col);
                // cout << board.size() << endl;
                // cout << board[1].size() << endl;
            }
            for (uint i = 0; i < length; i++)
            {
                this->board[row + i][col] = text[i];
            }
        }
    }

    // This function read a message from the board
    string Board::read(uint row, uint col, Direction direction, uint length)
    {
        string ans;

        if (empty)
        {
            for (int i = 0; i < length; i++)
            {
                ans += blank_cell;
            }
        }

        else
        {
            if (direction == Direction::Horizontal)
            {
                for (uint i = 0; i < length; i++)
                {
                    if ((col + i > max_col) || (row > max_row))
                    {
                        ans += blank_cell;
                    }
                    else
                    {
                        ans += board[row][col + i];
                    }
                }
            }
            else
            {

                for (uint i = 0; i < length; i++)
                {
                    if ((col > max_col) || (row + i > max_row))
                    {
                        ans += blank_cell;
                    }
                    else
                    {
                        ans += board[row + i][col];
                    }
                }
            }
        }

        return ans;
    }

    // This function print the board
    void Board::show()
    {
        for (uint i = min_row; i < max_row; i++)
        {
            for (uint j = min_col; j < max_col; j++)
            {
                cout << this->board[i][j];
            }
            cout << "\n";
        }
        // cout << "DONE";
    }
}