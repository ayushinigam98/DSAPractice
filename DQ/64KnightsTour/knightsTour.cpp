#include <iostream>
#include <vector>
using namespace std;

int directions = 8;
int diri[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dirj[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isSafe(int i, int j, int n)
{
    return (i>=0 && i<n && j>=0 && j<n);
}

void printBoards(vector<vector<int>> &chessBoard, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<chessBoard[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool knightsTour(vector<vector<int>> &chessBoard, int i, int j, int move, int n)
{
    if(move >= n*n)
    {
        //print the board
        printBoards(chessBoard, n);
        return true;
    }
    
    for(int d=0; d<directions; d++)
    {
        int nexti = i + diri[d];
        int nextj = j + dirj[d];
        
        if(isSafe(nexti, nextj, n) && chessBoard[nexti][nextj] == 0)
        {
            chessBoard[nexti][nextj] = move+1;
            if(knightsTour(chessBoard, nexti, nextj, move+1, n))
                return true;
            else
                chessBoard[nexti][nextj] = 0;
        }
    }

    return false;
    
}
/*
bool tour(vector<vector<int>> &move, int i, int j, int steps, int n)
{
    if(steps == n*n)
    {
        //print all the moves
        printBoards(move);
        return true;
    }

    for(int d=0; d<directions; d++)
    {
        int nexti = i + diri[d];
        int nextj = j + dirj[d];

        if(isSafe(nexti, nextj) && move[nexti][nextj] == 0)
        {
            move[nexti][nextj] = steps+1;
            if(tour(move, nexti, nextj, steps+1, n))
                return true;
            else
                move[nexti][nextj] = 0;
        }
        
    }

    return false;
}
*/
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> chessBoard(n);

    for(int i=0; i<n; i++)
    {
        chessBoard[i] = vector<int>(n);
        for(int j=0; j<n; j++)
        {
            chessBoard[i][j] = 0;
        }
    }

    chessBoard[0][0] = 1;
    printBoards(chessBoard, n);
    cout<<endl;
    //tour(chessBoard, 0, 0, 1, 8);
    knightsTour(chessBoard, 0, 0, 1, n);
    
    return 0;
}