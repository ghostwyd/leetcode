#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

//https://leetcode-cn.com/problems/palindrome-number/description/

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int reverse_num = 0;
    int tmp = x;
    while (tmp != 0) {
        reverse_num = reverse_num * 10 + tmp % 10;
        tmp = tmp / 10;
    }
    if (x != reverse_num) {
        return false;
    }
    return true;
}

int main(void) 
{
    return 0;
}
