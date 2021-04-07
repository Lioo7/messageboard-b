#include <vector>
#include <string>
#include "Direction.hpp"
using namespace std;

namespace ariel
{

    class Board
    {
    private:
        uint rows = 0;
        uint columns = 0;
        bool empty = true;
        vector<vector<char>> board;
        void boardResize(uint row, uint column);

    public:
        Board()
        {
            // init 0x0 board
            // board = vector<vector<char>>(100 , vector<char> (100, '_'));
            // rows = 100;
            // columns = 100;
            vector<char> temp;
            const char empty_place = '_';
            for (int i = 0; i < 10; i++)
            {
                temp.push_back(empty_place);
            }
            for (int i = 0; i < 10; i++)
            {
                this->board.push_back(temp);
            }
            
        }
        ~Board(){}; //destructor
        void post(uint row, uint col, Direction direction, string text);
        string read(uint row, uint col, Direction direction, uint length);
        void show();
    };

}
