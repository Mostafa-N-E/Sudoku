#ifndef GENRATE_SUDOKU_H
#define GENRATE_SUDOKU_H
#include <stdlib.h>
#include <iostream>
#include <solve_sudoku.h>

void generate(int init[1][9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            init[0][i][j] = {0};
        }
    }

    bool flag = true;
   int num ,ind, row, col;
//   int index[32] = {1,3,4,6,7,10,11,20,21,26,27,30,32,35,37,40,41
//                    ,42,45,47,50,52,55,56,61,62,71,72,75,76,78,79};
   int index[32] = {1,3,4,6,7,10,27,30,32,35,37,40,41,72,75,76,78,79};

   for(int i=0;i<32;i++){
       flag = true;
       ind = index[i]-1;
       row = ind/9;
       col = ind%9;
       while (flag) {
           num = (rand() % 9)+1;
           if(!UsedInRow(init, row, num) && !UsedInCol(init, col, num) && !UsedInBox(init, row - row % 3 , col - col % 3, num)){
               init[0][ row ][ col ] = num;
               flag = false;
           }
       }
   }

}

#endif // GENRATE_SUDOKU_H
