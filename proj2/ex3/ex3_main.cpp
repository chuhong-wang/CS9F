#include <vector> 
#include <iostream> 
#include "board.h"

using namespace std; 
// function definition 
void Board::SetCell(int player, int row, int col, char c){
    if (player==1) {
        row = size-1-row; 
        col = size-1-col; 
    }
    matx[row][col] = c;

}
void Board::Print(int player){
    if (player==0) {
        for (auto i=0;i!=size;++i){
            for (auto j=0;j!=size;++j){
                cout<<matx[i][j]<<" "; 
            }
            cout << endl; 

        }
    }
    else {
        for (auto i=size-1;i!=-1;--i){
            for (auto j=size-1;j!=-1;--j){
                cout<<matx[i][j]<<" "; 
            }
            cout << endl; 

        }
    }

}

int main(){
    Board board(19);
    board.SetCell(0, 0, 0, 'x');
    board.SetCell(0, 1, 2, 'c');
    board.SetCell(0, 1, 2, 'x');
    board.SetCell(0, 12, 6, 'x');
    board.SetCell(0, 4, 18, 'c');
    board.SetCell(0, 2, 9, 'x');
    board.Print(0); 
    cout<< endl;
    board.Print(1);
    return 0; 

}

