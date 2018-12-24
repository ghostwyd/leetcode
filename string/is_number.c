#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

//https://leetcode-cn.com/problems/valid-number/
/*
 * "a " false
 * "1 a" false
 * "1.4" true
 * "-1.4" true
 * "-1e3" true
 * "2.3e-3" true
 * ".4e6 true
 * ".e6" false
 * "4.e6" true
 * */
bool isNumber(const char* s) {
    size_t len = strlen(s);
    bool exponent_flag = false; 
    bool dot_flag = false;
    bool negtive_flag = false;
    size_t start = 0; 
    size_t end = len - 1;
    bool has_number = false;
    bool has_suffix = false;
    while (start < len && (s[start] == ' ' || s[start] == '\t')) {
        ++start;
    }

    while (end >= start && (s[end] == ' ' || s[end] == '\t')) {
        --end;
    }
    if (start == len || end < start) {
        return false;
    }
    for (size_t i = start; i <= end; ++i) {
        if (s[i] <= '9' && s[i] >= '0') {
            has_number = true;
            if (exponent_flag || negtive_flag) {
                has_suffix = true;
            }
            continue;        
        }
        if (s[i] == '.') {
            if (i != start && (s[i-1] > '9' || s[i-1] < '0') && s[i-1] != '+' && s[i-1] != '-') {
                return false;
            }
            if (dot_flag || exponent_flag) {
                return false;
            }
            dot_flag = true;
        } else if (s[i] == 'e') {
            if  (exponent_flag) {
                return false;
            }
            if (i == start || ((s[i-1] > '9' || s[i-1] < '0') && s[i-1] != '.')) {
                return false;
            }
            if (s[i-1] == '.' && i == start +1) {
                return false;
            }
            exponent_flag = true;
            negtive_flag = false;
            dot_flag = false;
            has_suffix = false;
        } else if (s[i] == '-' || s[i] == '+') {
            if (negtive_flag) {
                return false;
            }
            if (i == start || s[i-1] == 'e') {
                negtive_flag = true;
            } else {
                return false;
            }
            has_suffix = false;
        } else {
            return false;
        }
    }
    if (!has_number) {
        return false;
    }
    if ((exponent_flag || negtive_flag) && !has_suffix) {
        //printf("hit\n");
        return false;
    }
    return true;
}

int main(void)
{
    printf("%d\n", isNumber(" .e3 "));
}
