#include <iostream>
#include <vector>

using namespace std;

int increasej(int i, int j)
{
    if(j<8)
    {
        return j+1;
    }
    else
    {
       return 0;
    }
}
int increasei(int i, int j)
{
    if(j<8)
    {
        return i;
    }
    else
    {
       return i+1; 
    }
}

bool isPossible(vector<vector<int>> &sudoku, int i, int j, int num)
{

    for(int index=0; index<9; index++)
    {
        if(sudoku[i][index] == num)
            return false;

        if(sudoku[index][j] == num)
            return false;
    }

    int iCellStart = (i/3)*3;
    int jCellStart = (j/3)*3;
    
    for(int iCell = iCellStart; iCell<iCellStart+3; iCell++)
    {
        for(int jCell = jCellStart; jCell<jCellStart+3; jCell++)
        {
            if(sudoku[iCell][jCell] == num)
                return false;
        }
    }

    return true;

}

void print(vector<vector<int>> &sudoku)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sudokuSolver(vector<vector<int>> &sudoku, int i, int j)
{
    if(i >= 9)
    {
        //print the board
        print(sudoku);
    }
    else if(sudoku[i][j] != -1)
    {
        sudokuSolver(sudoku, increasei(i, j), increasej(i, j));
    }
    else
    {
        for(int num=1; num<=9; num++)
        {
            if(isPossible(sudoku, i, j, num))
            {
                sudoku[i][j] = num;
                sudokuSolver(sudoku, increasei(i, j), increasej(i, j));
                sudoku[i][j] = -1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> sudoku(9);

    for(int i=0; i<9; i++)
    {
        sudoku[i] = vector<int>(9);
        for(int j=0; j<9; j++)
        {
            cin>>sudoku[i][j];
        }
    }

    sudokuSolver(sudoku, 0, 0);


    return 0;
}