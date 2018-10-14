#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//https://leetcode-cn.com/problems/divide-two-integers/description/
int divide(int dividend, int divisor) {

    if (dividend == 0) {
        return 0;
    }
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        return 0-dividend;
    }

    int factor = 1;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        factor = -1;
    }
    if (dividend < 0) {
        dividend = 0 - dividend;
    }
    if (divisor < 0) {
        divisor = 0 - divisor;
    }

    int sum = 0;
    int mod_result = 0;
    while ((sum + divisor) <= dividend) {
        ++mod_result;
        sum += divisor;
    }
    if (factor > 0) {
        return mod_result;
    }
    return 0 - mod_result;
}

int main(void)
{
    printf("%d\n", divide(-1, 1));
    return EXIT_SUCCESS;
}
