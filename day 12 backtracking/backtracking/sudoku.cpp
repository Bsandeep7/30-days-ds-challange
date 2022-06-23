#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row,int col,int val,vector<vector<int>>& sudoku)
{

    for(int i=0;i<sudoku[0].size();i++)
    {
        cout<<sudoku[row][i]<<" "<<val<<" "<<endl;
        if(sudoku[row][i]==val)
        {
            return false;
        }
        if(sudoku[i][col]==val)
        {
            return false;
        }
        if(sudoku[3*(row/3)+ i/3][3*(col/3) + i%3]==val)
        {
            return false;
        }
    }
    return true;



}

bool solve(vector<vector<int>>& sudoku)
{
    int n=sudoku.size();
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<sudoku[0].size();col++)
        {
            if(sudoku[row][col]==0)
            {
                for(int y=1;y<=9;y++)
                {
                    if(isSafe(row,col,y,sudoku))
                    {
                        sudoku[row][col]=y;
                        if(solve(sudoku))
                        {
                            return true;
                        }
                        else{
                            sudoku[row][col]=0;
                        }
                    }
                }
                return false;

            }
        }
    }
    return true;



}


void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}

int main()
{
    vector<vector<int>>sudoku;
    for(int i=0;i<9;i++)
    {
        vector<int> temp;

        for( int j =0;j<9;j++)
        {

           int x;
           cin>>x;
           temp.push_back(x);
        }
        sudoku.push_back(temp);
    }

    solveSudoku(sudoku);






}
