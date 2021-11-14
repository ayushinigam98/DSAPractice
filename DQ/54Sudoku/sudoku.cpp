#include <iostream>
#include <vector>

using namespace std;

int incrementi(int i, int j)
{
    return (j<8)?i:(i+1);
}

int incrementj(int i, int j)
{
    return (j<8)?(j+1):0;
}

bool isSafe(vector<vector<int>> &sudokuBoard, int i, int j, int num)
{
    for(int k=0; k<9; k++)
    {
        if(sudokuBoard[i][k] == num || sudokuBoard[k][j] == num)
            return false;
    }

    int startCelli = (i/3)*3;
    int startCellj = (j/3)*3;

    for(int Celli=startCelli; Celli<startCelli+3; Celli++)
    {
        for(int Cellj=startCellj; Cellj<startCellj+3; Cellj++)
        {
            if(sudokuBoard[Celli][Cellj] == num)
                return false;
        }
    } 

    return true;
}

void printBoard(vector<vector<int>> &sudokuBoard)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<sudokuBoard[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sudokuHelper(vector<vector<int>> &sudokuBoard, int i, int j)
{
    if(i>=9)
    {
        //print the board
        printBoard(sudokuBoard);
        return ;
    }
    else if(sudokuBoard[i][j] != 0)
    {
        sudokuHelper(sudokuBoard, incrementi(i, j), incrementj(i, j));
        return ;
    }
    
    for(int num=1; num<=9; num++)
    {
        if(isSafe(sudokuBoard, i, j, num))
        {
            sudokuBoard[i][j] = num;
            sudokuHelper(sudokuBoard, incrementi(i, j), incrementj(i, j));
            sudokuBoard[i][j] = 0;
        }
    }
    
}

void sudoku(vector<vector<int>> &sudokuBoard)
{
    sudokuHelper(sudokuBoard, 0, 0);
}

int main()
{

    vector<vector<int>> sudokuBoard(9);

    for(int i=0; i<9; i++)
    {
        sudokuBoard[i] = vector<int>(9);
        for(int j=0; j<9; j++)
        {
            cin>>sudokuBoard[i][j];
        }
    }

    sudoku(sudokuBoard);

    return 0;
}