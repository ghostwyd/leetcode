#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * https://leetcode-cn.com/problems/two-sum/description/
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result_list = (int*)malloc(sizeof(int)*2); 
    result_list[0] = result_list[1] = 0;
    for (int i=0; i < (numsSize - 1); ++i) {
        for (int j =i+1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result_list[0] = i;
                result_list[1] = j;
                return result_list;
            }
        }
    }
    return result_list;
}


int main(void) {
}
