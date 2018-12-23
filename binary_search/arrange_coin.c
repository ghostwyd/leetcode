#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//https://leetcode-cn.com/problems/arranging-coins/

/*
 * use formula knowleage to solve the problem
 * assume type of k is double, and k*(k+1) = 2n;
 * then we can change the above equation to k^2 + 1/2 * k * 2 + 1/4 = 2n+1/4,
 * it's also euqal to (k+1/2)^2 = 2n + 1/4,then k = (log2(8*N+1)-1) /2
 */
int arrangeCoins(int n) {
    //parse n from int to long, in order to avoid overflow
    return (sqrt((((long)n) << 3) + 1) - 1) / 2;
}

//use binary serach
int arrangeCoinsII(int n) {
    
    return 0;
}

int main(void)
{
    printf("%d\n", arrangeCoins(1804289383));
    return 0;
}

