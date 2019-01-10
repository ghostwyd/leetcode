#include <stdlib.h>
#include <stdio.h>

int hammingWeight(uint32_t n) {
    int number = 0;
    for (int i = 0; i < 32 && n != 0; ++i)  {
        if (n % 2 == 1) {
            ++number;
        }
        n = n >> 1;
    }
    return number;
}
