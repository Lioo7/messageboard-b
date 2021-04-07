#include <map>
#include <string>
#include <climits>
#include "Direction.hpp"
using namespace std;

namespace ariel
{

    class Board
    {
    private:
        bool empty = true;
        map<uint, map<uint, char>> board;
        uint min_row = UINT_MAX;
        uint max_row = 0;
        uint min_col = UINT_MAX;
        uint max_col = 0;

    public:
        Board() {}
        ~Board(){}; //destructor
        void post(uint row, uint col, Direction direction, string text);
        string read(uint row, uint col, Direction direction, uint length);
        void show();
    };

}
