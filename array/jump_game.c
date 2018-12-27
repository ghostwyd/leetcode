#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//https://leetcode-cn.com/problems/jump-game/
bool canJump(int* nums, int numsSize) {
    int cover_range = 0;
    if (numsSize == 0) {
        return false;
    }
    for(int i = 0; i < numsSize-1; ++i)  {
        int cur_range = i + nums[i];
        if (cover_range < i) {
            break;
        }
        if (cur_range > cover_range && cover_range >= i) {
            cover_range = cur_range;
        } 
    }
    if (cover_range >= numsSize-1) {
        return true;
    }
    return false;
}
