## 1. 
> Write a function that takes a vector of integers as argument and reverses its elements.
```
vector<int> reverse(vector<int> &vec){
    for (unsigned i=0;i<vec.size()/2; ++i){
        auto tmp = vec[i];
        vec[i] = vec[vec.size()-i-1];
        vec[vec.size()-i-1] = tmp;
    }
}
```

## 2. 
> Write a program segment that, given a vector of vectors named vals and coordinates of one of its elements in row and col, prints the values that lie on the lower-left to upper-right diagonal of vals that contains the element with the given coordinates. The values should be printed one per line; it doesn't matter what order they are printed, except that you shouldn't print any element twice.
```
void print_diagonal(const vector<vector<int>> &vec, const size_type row, const vector<int>::size_type col){
    size_type r(row); 
    size_type c(col); 
    while (r!=vec.size() && c!=-1){
        cout<<vec[r][c]<<endl; 
        ++r;
        --c;
    }
    r = row-1; 
    c = col+1;
    while (r!=-1 && c!=vec[0].size()){
        cout<<vec[r][c]<<endl; 
        --r;
        ++c;
    }
}
```

## 3. 

> Complete the function below intended to play the game of "Treasure Hunt". In this game, you are given an initial clue, which leads you to the place of the next clue, which leads you to the next, and so on. Occasionally you will enter a loop, in which case you lose, and the function returns false. The "clues", for this problem, are index values in an 10-element vector; the value in a cell tells you the position of the next cell to look in. A position outside the vector means you win, and the function returns true.

In the example vector below, starting at position 0 leads you to 2, then 7, then 3, then 1, and you win. Starting at position 9 leads you to 7, 3, 1, and a win. Starting at 5 leads you to 8, then 4, then 6, then 8 where you repeat the previous steps, so you lose.
> 2    99    7    1    6    8    8    3    4    7

```
bool TreasureHunt( vector<int> &vec, int clue) {
    for (int numClues = 1; numClues < 11; numClues++) {
        if (clue < 0 || clue > 9) {
            return true;
        } else {
            clue = vec[clue]; // one statement goes here
        }
    }

    return false;  // more than 10 clues, so we must be in a loop.
}
```

## 4. 
> Consider a chess-playing program split into three files. One, in the file `playchess.cpp`, contains the code implementing the strategy for playing chess. A second, `board.cpp`, contains the code that implements the 8-by-8 board, using an 8-by-8 boolean vector of vectors, and the functions that move pieces and search the board. The third, `board.h`, declares the functions that `board.cpp` exports. Explain which of the three files might contain each of the following, and the context in which each might appear:
```
Board b // in playchess.cpp, it instantiates a board object. 
vector<vector<bool>> pieces     // in board.h, data member of board
vector<vector<bool>> pieces(8, 8) // illegal
vector<vector<bool>> pieces[0][0] // illegal 
```

## 5.
> Write a function that, given as argument a file of numbers open for input, reads and echoes all the values in the file to `cout`.
```
void echo(ifstream &fin){
    double number;
    while (fin>>number) cout << number <<endl; }
```
