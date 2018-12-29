#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

//https://leetcode-cn.com/problems/backspace-string-compare/
bool backspaceCompare(char* S, char* T) {
   size_t len1 = strlen(S); 
   size_t len2 = strlen(T); 
   size_t cur1 = 0;
   size_t cur2 = 0;
   while(cur1 < len1 && cur2 < len2) {
       while (cur1 < len1 && S[cur1] == '#') {
           ++cur1;
       }
       while (cur2 < len2 && T[cur2] == '#') {
           ++cur2;
       }
       if (cur2 >= len2 || cur1 >= len1) {
           return false;
       }
       if (T[cur2] != S[cur1])  {
           return false;
       }
       ++cur1;
       ++cur2;
   }
   if (cur1 == len1 && cur2 == len2) {
       return true;
   }
   return false;
}
