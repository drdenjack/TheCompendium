#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

void printBoard(vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << board[i][j] << " ";
            if(j==2 || j==5)
                cout << "| ";
        }
        cout << endl;
        if(i==2 || i==5)
            cout << "---------------------\n";
    }
}

void setVal(int available[9][9][9], int row, int col, int val)
{
    int start_row=row;
    while(start_row%3>0)
        start_row--;
    int start_col=col;
    while(start_col%3>0)
        start_col--;

    // cout << "Start row/col: " << start_row << "/" << start_col << endl;

    // cout << "block rows/cols" << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            // cout << "(" << i+start_row << "," << j+start_col << "): " << val-1 << endl;
            available[i+start_row][j+start_col][val-1]=0;
        }
    }
    for(int i=0;i<9;i++)
    {
        available[i][col][val-1]=0;
        available[row][i][val-1]=0;
        available[row][col][i]=0;
    }
    
}

void print_available(int available[9][9][9], int row, int col)
{
    cout << "pos: (" << row << "," << col << ")" << endl;

    for(int i=0;i<9;i++)
    {
        if(available[row][col][i])
            cout << i+1 << " ";
    }
    cout << endl;
    
}

void print_available(int available[9][9][9], int val)
{
    cout << "available vals: " << val << endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << available[i][j][val-1] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

int get_fill_val(int available[9][9][9], int row, int col)
{
    int val=0;
    int count=0;
    for(int i=0;i<9;i++)
    {
        if(available[row][col][i])
        {
            val=i+1;
            count++;
        }
    }
    if(count==1)
        return val;



    for(int i=0;i<9;i++)
    {
        int cr=0;
        for(int j=0;j<9;j++)
        {
            if(available[row][j][i])
                cr++;
        }

        if(cr==1 && available[row][col][i])
            return i+1;
    }
    
    
    for(int i=0;i<9;i++)
    {
        int cc=0;
        for(int j=0;j<9;j++)
        {
            if(available[j][col][i])
                cc++;
        }

        if(cc==1 && available[row][col][i])
            return i+1;
    }
    
    
    int start_row=row;
    while(start_row%3>0)
        start_row--;
    int start_col=col;
    while(start_col%3>0)
        start_col--;

    for(int i=0;i<9;i++)
    {
        int cc=0;
        for(int r=0;r<3;r++)
        {
            for(int c=0;c<3;c++)
            {
                if(available[r+start_row][c+start_col][i])
                    cc++;
            }
        }

        if(cc==1 && available[row][col][i])
            return i+1;
    }
    
    return 0;
    
}

void solveSudoku(vector<vector<char>>& board) {
        
    printBoard(board);
        
    int available[9][9][9]={0};
    
    // set all available spaces
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            for(int k=0;k<9;k++)
                available[i][j][k]=1;

    
    // fill existing values
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]!='.')
            {
                int val=board[row][col]-'0';

                // cout << "(" << row << "," << col << "): " << val << endl;
                setVal(available,row,col,val);
            }
        }
    }

    // print_available(available,4,2);
    // return;

    bool solved=false;
    int count=0;
    while(!solved && count<10)
    {
        solved=true;
        cout << endl << "count: " << ++count << endl;
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]=='.')
                {
                    // print_available(available,row,col);
                    // cout << "board[" << row << "][" << col << "]: " << board[row][col] << endl;
                    
                    solved=false;
                    int val=get_fill_val(available,row,col);
                    // cout << "val: " << val << endl;
                    if(val>0)
                    {
                        board[row][col]='0'+val;
                        // cout << "board[" << row << "][" << col << "]: " << board[row][col] << endl;
                        setVal(available,row,col,val);

                        
                    }
                }
            }
        }
            
        // for(int i=0;i<9;i++)
        // {
        //     cout << i << ": " << endl;
        //     for(int j=0;j<9;j++)
        //     {
        //         cout << " - " << available[1][i][j];
        //     }
        //     cout << endl;
        // }

        for(int i=0;i<9;i++)
        {
            print_available(available,i+1);
        }
        
        printBoard(board);
    }

    cout << endl << "FINISHED" << endl;
    
    printBoard(board);
        
    

    
        
}

vector<char> stringToVecChar(string s)
{
    vector<char> ret;
    for(int i=0;i<s.length();i++)
    {
        ret.push_back(s[i]);
    }
    return ret;
}


int main() {
	cout << "Sudoku Solver!" << endl;

        /*
          INPUT
        [[".",".","9","7","4","8",".",".","."],
         ["7",".",".",".",".",".",".",".","."],
         [".","2",".","1",".","9",".",".","."],
         [".",".","7",".",".",".","2","4","."],
         [".","6","4",".","1",".","5","9","."],
         [".","9","8",".",".",".","3",".","."],
         [".",".",".","8",".","3",".","2","."],
         [".",".",".",".",".",".",".",".","6"],
         [".",".",".","2","7","5","9",".","."]]
        */

        vector<vector<char>> board;
        // board.push_back(stringToVecChar("..9748..."));
        // board.push_back(stringToVecChar("7........"));
        // board.push_back(stringToVecChar(".2.1.9..."));
        // board.push_back(stringToVecChar("..7...24."));
        // board.push_back(stringToVecChar(".64.1.59."));
        // board.push_back(stringToVecChar(".98...3.."));
        // board.push_back(stringToVecChar("...8.3.2."));
        // board.push_back(stringToVecChar("........6"));
        // board.push_back(stringToVecChar("...2759.."));

        board.push_back(stringToVecChar("53..7...."));
        board.push_back(stringToVecChar("6..195..."));
        board.push_back(stringToVecChar(".98....6."));
        board.push_back(stringToVecChar("8...6...3"));
        board.push_back(stringToVecChar("4..8.3..1"));
        board.push_back(stringToVecChar("7...2...6"));
        board.push_back(stringToVecChar(".6....28."));
        board.push_back(stringToVecChar("...419..5"));
        board.push_back(stringToVecChar("....8..79"));

        solveSudoku(board);


        
/*
  Solution
  
[["5","1","9","7","4","8","6","3","2"],
 ["7","8","3","6","5","2","4","1","9"],
 ["4","2","6","1","3","9","8","7","5"],
 ["3","5","7","9","8","6","2","4","1"],
 ["2","6","4","3","1","7","5","9","8"],
 ["1","9","8","5","2","4","3","6","7"],
 ["9","7","5","8","6","3","1","2","4"],
 ["8","3","2","4","9","1","7","5","6"],
 ["6","4","1","2","7","5","9","8","3"]]
*/

            
	return 0;

}
