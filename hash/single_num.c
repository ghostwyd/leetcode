#include <stdlib.h>
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
   int result = 0;
   for (int i=0; i < numsSize; ++i) {
       result ^= nums[i];
   }
   return result;
}

int main() 
{
    return EXIT_SUCCESS;
}
