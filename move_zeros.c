#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/move-zeroes/description
void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i =0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }
    for (int j = k; j < numsSize; ++j) {
         nums[j] = 0;
    }
}

int main(void)
{
    return 0;
}
