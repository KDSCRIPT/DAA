#include <iostream>
using namespace std;
void printarray(int board[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<board[i][j]<<" ";
        }
         cout<<"\n";
    }
    cout<<"\n";
    exit(0);
}
bool is_safe(int board[8][8], int i, int j) 
{
    int j_left = j;
    int j_right = j;
    while (i >= 0) 
    {
        if ((j_left >= 0 && board[i][j_left] == 1) || board[i][j] == 1 || (j_right < 8 && board[i][j_right] == 1))
        {
            return false;
        }
        i -= 1;
        j_left -= 1;
        j_right += 1;
    }
    return true;
}

void rec(int board[8][8], int i)
{
    if (i == 8)
    {
        printarray(board);
    } 
    else 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (is_safe(board, i, j)) 
            {
                board[i][j] = 1;
                rec(board, i+1);
                board[i][j] = 0;
            }
        }
    }
}
int main() 
{
    int board[8][8]={};
    rec(board, 0);
}
