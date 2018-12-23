#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

//https://leetcode-cn.com/problems/isomorphic-strings/
bool isIsomorphic(char* s, char* t) {
    size_t len = strlen(s);
    short map[128];
    short used[128];
    for (int i=0; i < 128; ++i) {
        map[i] = -1;
        used[i] = 0;
    }

    for (size_t i = 0; i < len; ++i) {
        short a = s[i];
        short b = t[i];
        if (map[a] == -1 && used[b] == 0) {
            map[a] = b;
            used[b] = 1;
        }
        if (map[a] != b) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    char a[] = {'a', 'b', 0};
    char b[] = {'a', 'a', 0};
    printf("%d\n", isIsomorphic(a, b));
    return  0;
}
