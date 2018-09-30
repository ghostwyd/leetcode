#include <stdio.h>
#include <stdlib.h>

//https://leetcode-cn.com/problems/sort-colors/description/
void sortColors(int* nums, int numsSize) {
    int forward_index = 0;
    int backawrd_index = numsSize -1;
    while (forward_index < backawrd_index) {
        /*while (forward_index < numsSize && nums[forward_index] == 0){
            ++forward_index;
        }*/
        while(backawrd_index >= 0 && nums[backawrd_index] == 2) {
            --backawrd_index;
        }
        if (backawrd_index < 0) {
            break;
        }
        for (int k = backawrd_index - 1; k < )
    }
}

int main(void)
{
    return 0;
}
