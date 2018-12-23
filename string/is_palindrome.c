#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//https://leetcode-cn.com/problems/valid-palindrome/


bool isPalindrome(char* s) {
    if (strlen(s) == 0) {
        return true;
    }
    size_t start = 0;
    size_t end = strlen(s)-1;

    while(start < end) {
        while(start < end) {
           if ((s[start] >= 'a' && s[start] <= 'z') || (s[start] >= 'A' && s[start] <= 'Z') || (s[start] >= '0' && s[start] <= '9')) {
                break;
           }
           ++start;
        }
        while(end > start) {
           if ((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= '0' && s[end] <= '9')) {
                break;
           }
           --end;
       }

       if (end == start) {
           return true;
       }
       short a = s[start] - 'a';
       if (s[start] >= 'A' && s[start] <= 'Z') {
            a = s[start] - 'A';
       }
       short b = s[end] - 'a';
       if (s[end] >= 'A' && s[end] <= 'Z') {
            b = s[end] - 'A';
       }
       if (a != b) {
           return false;
       }
       ++start;
       --end;
    }
    return true;
}

int main(void)
{
    char array[] = {'"', '0', 'P', '"', '\0'};
    printf("%d\n", isPalindrome(array));
    return 0;
}
