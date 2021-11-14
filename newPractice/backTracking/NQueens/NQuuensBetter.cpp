#include <iostream>

using namespace std;

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printBoard(int columns[], int n)
{
    cout<<"---------------\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == columns[i])
            {
                cout<<"|Q";
            }
            else
            {
                cout<<"|X";
            }
        }
        cout<<endl;
    }
    cout<<"--------------\n";
}

void printPossibleBoards(int columns[], int n, int row, int attackedColumns[], int attackedD1[], int attackedD2[])
{
    if(row >= n)
    {
        //we need to print the board then return
        printBoard(columns, n);
        return;
    }

    //go through the possible places to place the queen in the row
    for(int col=0; col<n; col++)
    {
        //if the position (row, column) is not attacked then you can place it there and further recurse
        if(!attackedColumns[col] && !attackedD1[row-col+n-1] && !attackedD2[row+col])
        {
            //flag the attacked places
            attackedColumns[col] = 1;
            attackedD1[row-col+n-1] = 1;
            attackedD2[row+col] = 1;

            //store the column that the queen on row=row is stored in
            columns[row] = col;
        
            printPossibleBoards(columns, n, row+1, attackedColumns, attackedD1, attackedD2);
            
            //unflag the attacked places as (row, col) no longer has a queen
            attackedColumns[col] = 0;
            attackedD1[row-col+n-1] = 0;
            attackedD2[row+col] = 0;
        }

        
    }
}

int main()
{
    //number of rows and columns in the board
    int n;
    cin>>n;

    //array to store the number positions of the columns of the queens
    int columns[n];

    //to keep track of which position (row, column) are under attak
    int attackedColumns[n];
    int attackedD1[2*n-1];
    int attackedD2[2*n-1];

    for(int i=0; i<(2*n-1); i++)
    {
        attackedD1[i] = 0;
        attackedD2[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        attackedColumns[i] = 0;
    }

    printPossibleBoards(columns, n, 0, attackedColumns, attackedD1, attackedD2);

    return 0;
}