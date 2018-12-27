#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashNode {
    int val;
    int count;
    struct HashNode *next;
};

//https://leetcode-cn.com/problems/intersection-of-two-arrays/
//TODO:release hash node
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    const int hash_size = 9973;
    struct HashNode *hash_header[hash_size]; 
    memset(hash_header, 0, sizeof(struct HashNode*)*hash_size);
    int *return_ptr = NULL;
    size_t count = 0;

    int mod;
    struct HashNode *cur_ptr = NULL;
    for (int i = 0; i < nums1Size; ++i) {
        mod = nums1[i] % hash_size;
        mod = mod > 0 ? mod : -mod;
        cur_ptr = hash_header[mod];
        while (cur_ptr) {
            if (cur_ptr->val == nums1[i]) {
                break;
            }
            cur_ptr = cur_ptr->next;
        }
        if (cur_ptr != NULL) {
            continue;
        }
        struct HashNode *ptr = (struct HashNode*)calloc(1, sizeof(struct HashNode));
        ptr->val = nums1[i];
        ptr->count = 1;
        ptr->next = hash_header[mod];
        hash_header[mod] = ptr;
    }

    for (int i = 0; i < nums2Size; ++i) {
        mod = nums2[i] % hash_size;
        mod = mod > 0 ? mod : -mod;
        cur_ptr = hash_header[mod];
        while (cur_ptr != NULL) {
            if (cur_ptr->val == nums2[i] && cur_ptr->count > 0) {
                ++count;
                if (return_ptr == NULL) {
                    return_ptr = (int*)malloc(sizeof(int));
                    *return_ptr = nums2[i];
                } else {
                    return_ptr = (int*)realloc(return_ptr, sizeof(int)*count);
                    return_ptr[count-1] = cur_ptr->val;
                }
                --cur_ptr->count;
                break;
            }
            cur_ptr = cur_ptr->next;
        }
    }

    if (returnSize != NULL) {
        *returnSize = count;
    }
    return return_ptr;
}


//https://leetcode-cn.com/problems/intersection-of-two-arrays-II/
//TODO:release hash node
int* intersectionII(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    const int hash_size = 9973;
    struct HashNode *hash_header[hash_size]; 
    memset(hash_header, 0, sizeof(struct HashNode*)*hash_size);
    int *return_ptr = NULL;
    size_t count = 0;

    int mod;
    struct HashNode *cur_ptr = NULL;
    for (int i = 0; i < nums1Size; ++i) {
        mod = nums1[i] % hash_size;
        mod = mod > 0 ? mod : -mod;
        cur_ptr = hash_header[mod];
        while (cur_ptr) {
            if (cur_ptr->val == nums1[i]) {
                cur_ptr->count += 1;
                break;
            }
            cur_ptr = cur_ptr->next;
        }
        if (cur_ptr != NULL) {
            continue;
        }
        struct HashNode *ptr = (struct HashNode*)calloc(1, sizeof(struct HashNode));
        ptr->val = nums1[i];
        ptr->count = 1;
        ptr->next = hash_header[mod];
        hash_header[mod] = ptr;
    }

    for (int i = 0; i < nums2Size; ++i) {
        mod = nums2[i] % hash_size;
        mod = mod > 0 ? mod : -mod;
        cur_ptr = hash_header[mod];
        while (cur_ptr != NULL) {
            if (cur_ptr->val == nums2[i] && cur_ptr->count > 0) {
                ++count;
                if (return_ptr == NULL) {
                    return_ptr = (int*)malloc(sizeof(int));
                    *return_ptr = nums2[i];
                } else {
                    return_ptr = (int*)realloc(return_ptr, sizeof(int)*count);
                    return_ptr[count-1] = cur_ptr->val;
                }
                --cur_ptr->count;
                break;
            }
            cur_ptr = cur_ptr->next;
        }
    }

    if (returnSize != NULL) {
        *returnSize = count;
    }
    return return_ptr;
}
int main(void)
{
    int array1[] = {1,2,2,1};
    int array2[] = {2,2};
    int count = 0;
    int *ptr = intersectionII(array1, 4, array2, 2, &count);
    for (int i = 0; i < count; ++i) {
        printf("%d\n", ptr[i]);
    }
    return 0;
}
