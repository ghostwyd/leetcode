#include <stdlib.h>
#include <stdio.h>

int trailingZeroes(int n) {
    int cnt = 0;
    for (int i = 5; i <= n ; i=i) {
        cnt += i;
    }
    return cnt;
}
