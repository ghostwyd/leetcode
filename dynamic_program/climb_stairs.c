#include <stdio.h>
#include <stdlib.h>

//https://leetcode-cn.com/problems/climbing-stairs/description/
int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int behind_1 = 1;
    int behind_2 = 1;
    int cur_count = 0;
    for (int i=2; i<=n; ++i) {
       cur_count = behind_1 + behind_2; 
       behind_2 = behind_1;
       behind_1 = cur_count;
    }
    return cur_count;
}

int main(void)
{
    printf("%d\n", climbStairs(3));
    return EXIT_SUCCESS;
}
