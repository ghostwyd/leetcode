#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//https://leetcode-cn.com/problems/maximum-subarray/
int maxSubArray(int* nums, int numsSize) {
    int max;
    int adjacent_max;
    if (numsSize == 0) {
        return 0;
    }

    max = adjacent_max = nums[0];
    for (int i= 1; i < numsSize; ++i) {
        if (adjacent_max < 0) {
            adjacent_max = nums[i];
        } else {
            adjacent_max += nums[i];
        }
        if (adjacent_max > max) {
            max = adjacent_max;
        }
    }
    return max;
}
