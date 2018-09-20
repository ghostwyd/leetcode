#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//https://leetcode-cn.com/problems/next-permutation/description/

void nextPermutation(int* nums, int numsSize) {
    if (numsSize == 0) {
        return;
    }

    //print origin nums
    for (int i = 0; i < numsSize-1; ++i) {
        printf("%d, ", nums[i]);
    }
    printf("%d -> ", nums[numsSize -1]);

    int last_index = 0;
    for (int i = numsSize -1 ; i > 0; i--)  {
        if (nums[i-1] < nums[i]) {
            last_index = i;
            break;
        }
    }   
    int start = last_index; 
    int end = numsSize -1;
    int tmp = 0;
    while (start < end) {
        tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        ++start;
        --end; 
    }

    if (last_index != 0) {
        for (int k = last_index; k < numsSize; ++k) {
            if (nums[last_index -1] < nums[k]) {
                tmp = nums[last_index - 1];
                nums[last_index -1] = nums[k];
                nums[k] = tmp;
                break;
            }
        }
    }

    //print next permutation
    for (int i = 0; i < numsSize-1; ++i) {
        printf("%d, ", nums[i]);
    }
    printf("%d\n", nums[numsSize-1]);
}

int main(void)
{
    /*int *array = (int*)malloc(sizeof(int) * 10);
    assert(array != NULL);
    for (int i = 0; i < 10; i++) {
        array[i] = 1;
    }*/
    int array[] = {1,3,2};
    nextPermutation(array, 3);
    return 0;
}
