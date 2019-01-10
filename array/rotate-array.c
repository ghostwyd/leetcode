#include <stdlib.h>
#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return;
    }
    for (int i = 0; i< k; ++i) {
        int last = nums[numsSize-1];
        for (int j=numsSize-1; j>0; --j) {
            nums[j] = nums[j-1];
        }
        nums[0] = last;
    }
}
