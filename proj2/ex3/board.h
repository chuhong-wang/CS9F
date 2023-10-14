#ifndef BOARD_H
#define BOARD_H

#include <vector> 

using namespace std; 

struct Board{
    public:
        Board(int n):size(n), matx(n, vector<char>(n, '.')){}; 
        void SetCell(int player, int row, int col, char c); 
        void Print(int player); 

    private:
        vector<vector<char>> matx; 
        unsigned size; 

}; 


#endif 