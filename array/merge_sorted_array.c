#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//https://leetcode-cn.com/problems/merge-sorted-array/
void merge(int* nums1, int m, int* nums2, int n) {
   int first = m-1; 
   int second = n -1;
   int index = m+n-1;
   while (first >=0 || second >= 0) {
       if (first < 0) {
            nums1[index] = nums2[second];
            --second;
        } else if (second < 0) {
            nums1[index] = nums1[first];
            --first;
        } else {
            if (nums1[first] > nums2[second]) {
                nums1[index] = nums1[first];
                first--;
            } else {
                nums1[index] = nums2[second];
                --second;
            }
        }
       --index;
   }
}

void mergeII(int* nums1, int m, int* nums2, int n) {
   int first = m-1; 
   int second = n -1;
   int index = m+n-1;
   while (first >=0 || second >= 0) {
       if (first < 0) {
            memmove(nums1, nums2, sizeof(int)*(second+1));
            return;
        } else if (second < 0) {
            memmove(nums1, nums1, sizeof(int)*(first+1));
            return;
        } else {
            if (nums1[first] > nums2[second]) {
                nums1[index] = nums1[first];
                first--;
            } else {
                nums1[index] = nums2[second];
                --second;
            }
        }
       --index;
   }
}
