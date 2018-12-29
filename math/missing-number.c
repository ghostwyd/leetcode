#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/missing-number/
int missingNumber(int* nums, int numsSize) {
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        while (sum >= numsSize) {
            sum -= numsSize;
            ++cnt;
        }
    }
    float supposed_cnt = (numsSize+1.0) / 2;
    return (int)((supposed_cnt-cnt)*numsSize - sum);
}
