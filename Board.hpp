#include <vector>
#include <string>
#include "Direction.hpp"
using namespace std;

namespace ariel{

class Board{
private:
uint rows;
uint columns;
vector<vector<char>> board;  

public:
Board() {
    // init 0x0 board
    board = vector<vector<char>>(0 , vector<char> (0, '_')); 
    rows = 0;
    columns = 0;
}
 ~Board(){}; //destructor
void post(uint row, uint column, Direction direction, string text);
string read(uint row, uint column, Direction direction, uint length);
void boardResize(uint row, uint column);
void show();
};

}
