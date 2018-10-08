#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

//https://leetcode-cn.com/problems/string-to-integer-atoi/description/
int myAtoi(char* str) {
    int result = 0;
    char *ptr = str;
    while(*ptr != '\0' && *ptr == ' ') {
        ++ptr;
    }
    if (*ptr == '\0' || (*ptr != '+' && *ptr != '-' && (*ptr > '9' || *ptr < '0'))) {
        return result;
    }
    int flag = 1;
    if (*ptr == '+' || *ptr == '-') {
        if (*ptr == '-') {
            flag = -1;
        }
        ++ptr;
    }
    while (*ptr <= '9' && *ptr >= '0') {
        int tmp = (*ptr - '0') * flag;
        if (result > 0 && (INT_MAX/10 < result || (result == INT_MAX/10 && tmp > 7))) {
            return INT_MAX;
        }
        if (result < 0 && (INT_MIN/10 > result || (result == INT_MIN/10 && tmp < -8))) {
            return INT_MIN;
        }
        result = result * 10 + tmp;
        ++ptr;
    }
    return result;
}

int main(void) 
{
    char str[] = "-91283472332";
    printf("%d\n", myAtoi(str));
    return 0;
}
