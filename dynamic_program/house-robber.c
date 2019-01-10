#include <stdlib.h>
#include <stdio.h>

int rob(int* nums, int numsSize) {
    int before = 0;    
    int curr = 0;
    for (int i = 0; i < numsSize; ++i) {
        int tmp = curr;
        curr = curr > before + nums[i] ? curr:before + nums[i];
        before = tmp;
    }
    return curr;
}
