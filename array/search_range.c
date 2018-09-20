#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int return_list = (int*)malloc((*returnSize) * sizeof(int));
    int start = 0;    
    int end = numsSize-1;
    int mid = 0;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid -1;
        } else {
            
        } 
    }
}

int main(void)
{
    return 0;
}
