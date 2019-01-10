#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

//https://leetcode-cn.com/problems/backspace-string-compare/
bool backspaceCompare(const char* S, const char* T) {
      char *S1 = (char*)malloc(strlen(S)+1);
      char *T1 = (char*)malloc(strlen(T)+1);
      int index = 0;
      for (size_t i = 0; i < strlen(S); ++i) {
         if (S[i] != '#')  {
             S1[index++] = S[i];
         } else if (index > 0) {
                 --index;
         }
      }
      S1[index] = '\0';
      index = 0;
      for (size_t i = 0; i < strlen(T); ++i) {
         if (T[i] != '#')  {
             T1[index++] = T[i];
         } else if (index > 0) {
                 --index;
         }
      }
      T1[index] = '\0';
    
      return strcmp(S1, T1) == 0;
}

int main(void)
{
    printf("%d\n", backspaceCompare("ab#c", "ad#c"));
    return 0;
}
