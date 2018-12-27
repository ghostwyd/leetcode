#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

//https://leetcode-cn.com/problems/permutation-in-string/
bool checkInclusion(char* s1, char* s2) {
    short counter[128];
    short counter2[128];
    memset(counter, 0, sizeof(counter));
    size_t len = strlen(s1);
    for(size_t i = 0; i < len; ++i) {
        ++counter[(size_t)s1[i]];
    }
    len = strlen(s2);
    memcpy(counter2, counter2, sizeof(short)*128); 
    index
    for (size_t i = 0; i < len; ++i) {
        if (counter2[size_t(s2[i])] < 0 ) {
            continue;
        }


    }
    return false;

    
}
