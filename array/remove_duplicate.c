#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) {
        return numsSize;
    }

    int k = 1;
    int pre_value = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (pre_value != nums[i]) {
            nums[k] = nums[i];
            k++;
            pre_value = nums[i];
        }
    }
    return k;
}

int main(void)
{
    return 0;
}
