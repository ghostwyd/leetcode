#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/remove-element/description/
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i =0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            ++k;
        }
    }
    return k;
}

int main(void)
{
    return 0;
}
