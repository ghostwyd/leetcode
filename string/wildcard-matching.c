#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//https://leetcode-cn.com/problems/wildcard-matching/
bool isMatch(const char* s, const char* p) {
    size_t s_len = strlen(s);
    size_t p_len = strlen(p);
    if (s_len == 0 && p_len == 0) {
        return true;
    }

    //   printf("s:%s p:%s\n", s, p);
    while (*s != '\0' && *p != '\0') {
        switch (*p) {
            case '?':
                ++s;
                ++p;
                break;
            case '*':
                while(*p == '*') {
                    ++p;
                }
                const char *tmp = s;
                while(1) {
                    if (isMatch(tmp, p)) {
                        return true;
                    }
                    if (*tmp == '\0') {
                        break;
                    }
                    ++tmp;
                }
                return false;
            default:
                if (*s == *p) {
                    ++s;
                    ++p;
                } else {
                    return false;
                }
        }
    }
    return false;
}

int main(void)
{
    /*printf("%d\n", isMatch("b", "*?*?"));
      printf("-----------------------------\n");
      printf("%d\n", isMatch("bb", "bb**"));
      printf("-----------------------------\n");*/
    printf("%d\n", isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b"));
    printf("%d\n", isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
    return EXIT_SUCCESS;
}
