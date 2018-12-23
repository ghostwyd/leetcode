#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <strings.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    int min_len = INT_MAX;
    int i = 0; 
    int j = 0; 
    for (; i < strsSize; ++i) {
        int len = strlen(strs[i]);
        if (len < min_len) {
            min_len = len; 
        }
    }
    for (i = 0; i < min_len; ++i) {
        char curr = strs[0][i];
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != curr) {
                break;
            }
        }
        if (j != strsSize) {
            break;
        }
    }
    char *ptr = (char*)malloc(i+1);
    memcpy(ptr, strs[0], i);
    ptr[i]= '\0';
    return ptr;
}

struct TrieEntry {
    struct TrieEntry *sub[26];
    int sub_cnt;
};

//use trie tree to solve the problem
char* longestCommonPrefixII(char** strs, int strsSize) {
    struct  TrieEntry *trie_root = (struct TrieEntry*)calloc(sizeof(struct TrieEntry), 1);

    int depth = 0;
    int min_len = INT_MAX;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) < min_len) {
            min_len = strlen(strs[i]);
        }
        depth = 0;
        struct TrieEntry *curr = trie_root;
        for (size_t j = 0; j < strlen(strs[i]); j++) { 
            int index = (int)(strs[i][j] - 'a');
            if (curr->sub[index] == NULL) {
                curr->sub[index] = (struct TrieEntry*)calloc(sizeof(struct TrieEntry), 1);
                curr->sub_cnt += 1;
            }
            if (curr->sub_cnt > 1) {
                break;
            }
            ++depth;
            curr = curr->sub[index];
        }
    }
    depth = depth > min_len ? min_len:depth;
    char *prefix_str = (char*)malloc(sizeof(char)*(depth+1));
    memcpy(prefix_str, strs[0], depth);
    prefix_str[depth]= '\0';
    
    return prefix_str;

}

int main(void)
{
    char *array[] = {"baab","bacb","b","cbc"};
    printf("%s\n", longestCommonPrefixII(array, 4));
    return 0;
}
