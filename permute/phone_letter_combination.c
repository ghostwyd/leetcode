#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || strlen(digits) == 0) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }
        return NULL;
    }
    char *letter_map[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    //TODO:handle malloc fail
    int *array = malloc(sizeof(int)*strlen(digits));
    *returnSize = 1;
    int num = 0;
    for (int i = 0; i < strlen(digits); ++i) {
        array[i] = 0;
        num = digits[i]  - '2';
        if (num == 5 || num == 7) {
            *returnSize *= 4;
        } else {
            *returnSize *= 3; 
        }
    }

    char **combination_array = (char**)malloc(sizeof(char*)*(*returnSize + 1));
    combination_array[*returnSize] = NULL;

    int digtal_count = strlen(digits);
    int cur_index = 0;
    int need_forward = 0;
    while (1) {
        int need_check = -1;
        for (int i = digtal_count - 1; i >= 0; --i) {
            int max_num = 3;
            num = digits[i] - '2';
            if (num == 5 || num == 7)  {
                max_num = 4;
            }
            if (need_forward) {
                array[i] += 1;
            }
            if (array[i] < max_num) {
                need_forward = 0;
                break;
            } else {
                need_forward = 1;
                array[i] = 0;
            }
        }
        if (need_forward) {
            break;
        }

        char *leeter_array = (char*)malloc(sizeof(char)*(digtal_count + 1));
        for (int i =0 ; i < digtal_count; ++i) {
            num = digits[i] - '2';
            leeter_array[i] = letter_map[num][array[i]]; 
        }
        leeter_array[digtal_count] = 0;
        combination_array[cur_index++] = leeter_array;
        //printf("%s\n", leeter_array);
        ++array[digtal_count -1];
    }

    free(array);
    return combination_array;
}


int main(void)
{
    const char *test_digits = "23";
    char *digits = (char*)malloc(sizeof(char)*(strlen(test_digits)+1));
    strcpy(digits, test_digits);
    int returnSize = 0;
    letterCombinations(digits, &returnSize);
    printf("returnSize:%d\n", returnSize);
    return 0;
}

