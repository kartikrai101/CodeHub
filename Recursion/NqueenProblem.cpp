#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int> > &ans, vector<vector<int> > &board){
    vector<int> temp;
    int n = board.size(); // this gives the number of rows in board which is 'n'

    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            temp.push_back(board[i][j]);
        }
    }

    return temp;
}

bool isSafe(int row, int col, vector<vector<int> > &board, int n){
    int x=row;
    int y = col;

    // check if there's a queen in the same row
    // notice that we are only checking for the elements in the row from
    // column no. 0 to column number y. This is so because we are inserting
    // the queens on the board from left to right, so whenever this isSafe 
    // function is called, there won't be any queen placed to the right side
    // of the current column for which the function has been called
    while(y>=0){
        if(board[x][y] == 1)
            return false;
        y--;
    }

    // now we do not even need to check for the presence of more than one
    // queen in the same column because the solve function is written in 
    // such a way that it places one queen in one column and then makes the re
    // -cursive call for the next column, so we'll never have a situation 
    // where there is more than one queen in the same column

    x = row;
    y = col;

    // check if there's a queen in the same diagonal

    // checking in the upward diagonal direction
    while( x>=0 && y>=0){
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    // checking in the downward diagonal direction
    while( x<n && y>=0){
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int> > &ans, vector<vector<int> > &board, int n){
    // base case
    if(col == n){
        addSolution(board, ans); // basically jo bhi solution board mein
        // pda hua hai usko ans mein store kra denge iss function k through
        return; 
    }

    // solve 1 case and recursion will take care of rest of the cases

    // toh pehle humey pehli column ki saari rows pe jaana hai
    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, ans, board, n);

            // backtrack : jo queen place ki thi usko board se remove krna padega
            board[row][col] = 0;

        }
    }
}

vector<vector<int> > nQueens(int n){
    vector<vector<int> > board(n, vector<int> (n, 0)); // making a board 
    // with all the values assigned to be 0 by default
    vector<vector<int> > ans;

    solve(0, ans, board, n);

    return ans;
}

int main(){

}