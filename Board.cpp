#include "Board.hpp"
#include <iostream>

using namespace std;
const char blank_cell = '_';

namespace ariel
{
    // This function post a new post in the board
    void Board::post(uint row, uint col, Direction direction, string text)
    {
        uint length = text.length();
        if (length > 0)
        {
            empty = false;
        }

        else
        {
            return;
        }

        if (direction == Direction::Horizontal)
        {
            this->min_row = min(min_row, row);
            this->min_col = min(min_col, col);
            this->max_row = max(max_row, row);
            this->max_col = max(max_col, col + length);

            for (uint i = 0; i < length; i++)
            {
                this->board[row][col + i] = text.at(i);
            }
        }

        else
        {
            this->min_row = min(min_row, row);
            this->min_col = min(min_col, col);
            this->max_row = max(max_row, row + length);
            this->max_col = max(max_col, col);

            for (uint i = 0; i < length; i++)
            {
                this->board[row + i][col] = text.at(i);
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
                    if (board[row][col + i] == 0)
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
                    if (board[row + i][col] == 0)
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
        for (uint i = min_row-1; i < max_row; i++)
        {
            for (uint j = min_col; j < max_col; j++)
            {
                if (board[i][j] != 0)
                {
                    cout << board[i][j];
                }
                else
                {
                    cout << '_';
                }
            }
            cout << "\n";
        }

        // cout << "min_row: " << min_row << "\n";
        // cout << "max_row: " << max_row << "\n";
        // cout << "min_col: " << min_col << "\n";
        // cout << "max_col: " << max_col << "\n";
    }
}