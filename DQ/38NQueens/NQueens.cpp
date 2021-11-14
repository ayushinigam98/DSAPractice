#include <iostream>
#include <vector>

using namespace std;

bool isAttacked(int Qi, int Qj, int i, int j)
{
    return ((Qj == j) || ((Qi-i) == (Qj-j)) || ((Qi-i) == (-Qj+j)));
}

void printBoard(vector<int> &queenColumn, int n)
{
    for(int i=0; i<queenColumn.size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == queenColumn[i])
            {
                cout<<"|Q";
            }
            else
            {
                cout<<"|X";
            }
        }
        cout<<"|"<<endl;
    }

    cout<<"-------------------\n";
}

void QueenPositions(vector<int> &queenColumn, int row, int n)
{
    if(row >= n)
    {
        printBoard(queenColumn, n);
        return;
    }

    for(int col=0; col<n; col++)
    {
        //check if the position (row, col) is attacked by any of the previously placed queens
        bool isValid = true;
        for(int Qrow = 0; Qrow < row && isValid; Qrow++)
        {
            isValid = (isValid && !isAttacked(Qrow, queenColumn[Qrow], row, col));
        }

        if(isValid)
        {
            queenColumn[row] = col;
            QueenPositions(queenColumn, row+1, n);
        }
    }
}

int main()
{   int n;
    cin>>n;
    vector<int> queenColumn(n);

    QueenPositions(queenColumn, 0, n);

    return 0;
}