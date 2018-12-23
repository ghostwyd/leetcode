#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(const char* s) {

    int flag[128];
    int start = 0; 
    int longest = 0; 
    size_t len = strlen(s);

    for (int i = 0; i < 128; ++i) {
        flag[i] = -1;
    }

    start = 0;
    for (size_t i = 0; i < len; ++i) {
        int index = s[i];
        if (flag[index] != -1 && flag[index] >= start) {
            if (i - start > longest) {
                longest = i - start;
            }
            start = flag[index] + 1;
        }
        flag[index] = i;

    }
    if  (len - start > longest) {
        longest = len - start;
    }
    return longest;
}

int main(void)
{
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("abcdefghijklmn"));
    return 0;
}

