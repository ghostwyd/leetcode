#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/unique-paths/

//TODO:release memory
int uniquePaths(int m, int n) {
    int **array = (int**)malloc(sizeof(int*)*m);   
    for (int i=0; i<m; ++i) {
        array[i] = (int*)calloc(n,sizeof(int));
    }
    array[0][0] = 1;
    for (int  i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i -1 >= 0) {
                array[i][j] = array[i-1][j];
            }
            if (j-1>=0) {
                array[i][j] += array[i][j-1];
            }
        }
    }
    return array[m-1][n-1];
}


