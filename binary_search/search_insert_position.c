#include <stdio.h>
#include <stdlib.h>

//https://leetcode-cn.com/problems/search-insert-position/
int searchInsert(int* nums, int numsSize, int target) {
    int start = 0; 
    int end = numsSize -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target) {
            end = mid-1;
        } else if (nums[mid] < target){
            start = mid + 1;
        } else {
            return mid;
        }

    }
    return start;
}

int main(void)
{
    int nums[] = {1,3,5,6};    
    int target_list[] = {5,2,7,0};
    for (int i = 0; i < 4; i++) {
        printf("%d\n", searchInsert(nums, 4, target_list[i]));
    }
    
    return 0;
}

