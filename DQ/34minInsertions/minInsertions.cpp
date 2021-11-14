#include <iostream>

using namespace std;

string minpalindrone(string str)
{
    int n = str.length();

    int minChar[n][n];
    string palindrone[n][n];
    
    for(int i=0; i<n; i++)
    {
        minChar[i][i] = 0;
        palindrone[i][i] = str[i];
    }
    for(int i=0; i<n-1; i++)
    {
        minChar[i+1][i] = 0;
        palindrone[i+1][i] = "";
    }

    //base cases done

    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j = i + l - 1;
            
            if((1 + minChar[i+1][j]) < (1 + minChar[i][j-1]))
            {
                minChar[i][j] = 1 + minChar[i+1][j];
                palindrone[i][j] = str[i] + palindrone[i+1][j] + str[i]; 
            }
            else
            {
                minChar[i][j] = 1 + minChar[i][j-1];
                palindrone[i][j] = str[j] + palindrone[i][j-1] + str[j];
            }

            if(str[i] == str[j])
            {
                if(minChar[i+1][j-1] < minChar[i][j])
                {
                    minChar[i][j] = minChar[i+1][j-1];
                    palindrone[i][j] = str[i] + palindrone[i+1][j-1] + str[j];
                }
            }
            else
            {
                if((2 + minChar[i+1][j-1]) < minChar[i][j])
                {
                    minChar[i][j] = 2 + minChar[i+1][j-1];
                    palindrone[i][j] = "";
                    palindrone[i][j] = palindrone[i][j] + str[i];
                    palindrone[i][j] = palindrone[i][j] + str[j];
                    palindrone[i][j] = palindrone[i][j] + palindrone[i+1][j-1] + str[j];
                    palindrone[i][j] = palindrone[i][j] + str[i];
                }
            }
        }
    }

    return palindrone[0][n-1];
}

int main()
{
    string str;
    cin>>str;

    cout<<minpalindrone(str);

    return 0;
}