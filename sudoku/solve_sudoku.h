#ifndef SOLVE_SUDOKU_H
#define SOLVE_SUDOKU_H

#define UNASSIGNED 0
#define N 9

#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool FindUnassignedLocation(int grid[1][N][N], int &row, int &col);
bool isSafe(int grid[1][N][N], int row, int col, int num);

bool SolveSudoku(int grid[1][N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[0][row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[0][row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool FindUnassignedLocation(int grid[1][N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[0][row][col] == UNASSIGNED)
                return true;
    return false;
}


bool UsedInRow(int grid[1][N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[0][row][col] == num)
                return true;
    return false;
}

bool UsedInCol(int grid[1][N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[0][row][col] == num)
                return true;
    return false;
}

bool UsedInBox(int grid[1][N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[0][row+boxStartRow][col+boxStartCol] == num)
                    return true;
    return false;
}

bool isSafe(int grid[1][N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}
bool ckeckInRow(int grid[1][N][N], int row, int num)
{
    int count=0;
    for (int col = 0; col < N; col++)
        if (grid[0][row][col] == num){
            if(count>1)
                return true;
            count++;
        }
    return false;
}

bool ckeckInCol(int grid[1][N][N], int col, int num)
{
    int count=0;
    for (int row = 0; row < N; row++)
        if (grid[0][row][col] == num){
            if(count>1)
                return true;
            count++;
        }
    return false;
}

bool ckeckInBox(int grid[1][N][N], int boxStartRow, int boxStartCol, int num)
{
    int count=0;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[0][row+boxStartRow][col+boxStartCol] == num){
                count++;
                if(count>1)
                    return true;

            }
    return false;
}
bool is_solve(int grid[1][N][N]){
    int num;
    for(int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            num = grid[0][i][j];
            if(ckeckInRow(grid, i, num) || ckeckInCol(grid, j, num) || ckeckInBox(grid, i - i % 3 , j - j % 3, num)){
                return false;
            }
        }
    }
    return true;
}

#endif // SOLVE_SUDOKU_H
