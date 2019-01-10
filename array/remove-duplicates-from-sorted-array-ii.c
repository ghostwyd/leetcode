#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int size = 0;    
    int cur = nums[0];
    int cur_index = 0; 
    int tmp = 0;

    while (cur_index < numsSize) {
        tmp = cur_index;
        while(cur_index <  numsSize && nums[cur_index] == cur) {
            ++cur_index;
        }
        for (int j = 0; j < cur_index - tmp && j < 2; ++j) {
           nums[size++]  = cur;
        }
        if (cur_index == numsSize) {
            break;
        }
        cur = nums[cur_index];
    }
    return size;
}
