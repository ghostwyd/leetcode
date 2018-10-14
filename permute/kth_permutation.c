#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/permutation-sequence/description/
char* getPermutation(int n, int k) {
    int left = k;
    int mod_base = 1;
    for (int i=2; i<n; ++i) {
        mod_base*= i;
    }
    
    char *str_kth = (char*)malloc(sizeof(char)*(n+1));
    int *array = (int*)calloc(n, sizeof(int));
    char *ptr = str_kth;

    for (int i = n; i > 1 && left != 0; i--)  {
        
        int mod_result = left / mod_base;
        if (left % mod_base != 0) {
            mod_result += 1;
        }
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (array[j] == 0) {
               k++;
               if (k == mod_result || mod_result == 0) {
                   array[j] = 1;
                   *ptr = (char)('0'+j+1);
                   ++ptr;
                   break;
               }
            }
        }//end of for
        left = left % mod_base; 
        mod_base /= (i-1);
    } 
    for (int i = n-1; i >= 0; --i) {
        if (array[i] == 0) {
            *(ptr++) = (char)(i+'0'+ 1);
        }
    }

    free(array);
    str_kth[n] = '\0';
    return str_kth;
} 

int main(void)
{
    printf("%s\n", getPermutation(3, 3)); 
    printf("%s\n", getPermutation(4, 9)); 
    printf("%s\n", getPermutation(1, 1)); 
    return EXIT_SUCCESS;
}
