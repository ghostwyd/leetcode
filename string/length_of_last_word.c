#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://leetcode-cn.com/problems/length-of-last-word/description/
int lengthOfLastWord(char* s) {
    int str_len = strlen(s); 
    int last_word_len = 0;
    int index = str_len - 1;
    while (index >=0 && s[index] == ' ') {
        --index;
    }
    for (int i=index; i>=0; i--) {
       if (s[i] != ' ') {
           ++last_word_len;
       } else {
           break;
       }
    }
    return last_word_len;

}

int main(void)
{
    return EXIT_SUCCESS;
}
