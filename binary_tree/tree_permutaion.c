#include <stdio.h>
#include <stdlib.h>

//https://leetcode-cn.com/problems/unique-binary-search-trees/description/
int numTrees(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int *array = (int*)malloc(sizeof(int)*(n+1));
    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i <= n; ++i) {
        array[i] = 0;
        for (int j = 0; j < i; ++j) {
            array[i] += array[j] * array[i-j-1];
        }
    }

    free(array);
    return array[n];
}


int main(void)
{
    printf("%d\n", numTrees(3));
    return EXIT_SUCCESS;
}
