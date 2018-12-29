#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//https://leetcode-cn.com/problems/power-of-two/
bool isPowerOfTwo(int n) {
    return n > 0 && (n&(n-1)) == 0;
}
