#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

//https://leetcode-cn.com/problems/implement-trie-prefix-tree/

typedef struct Trie_Tag{
    struct Trie_Tag *sub[26];   
    int end_tag;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie *trie_ptr = (Trie*)calloc(sizeof(Trie), 1);   
    return trie_ptr;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    Trie *cur = obj;
    size_t len = strlen(word);    
    for (size_t i = 0; i < len; ++i) {
        int index = word[i] - 'a';   
        if (cur->sub[index] == NULL) {
            cur->sub[index] = trieCreate();
        }
        cur = cur->sub[index];
    }
    cur->end_tag = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    Trie *cur = obj;
    size_t len = strlen(word);    
    for (size_t i = 0; i < len; ++i) {
        int index = word[i] - 'a';
        if (cur->sub[index] == NULL){
            return false;
        }
        cur = cur->sub[index];
    }
    if (cur->end_tag) {
        return true;
    }
    return false;

}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    Trie *cur = obj;
    size_t len = strlen(prefix);    
    for (size_t i = 0; i < len; ++i) {
        int index = prefix[i] - 'a';
        if (cur->sub[index] == NULL){
            return false;
        }
        cur = cur->sub[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (!obj) {
        return;
    }
    for (size_t i = 0; i < 26; i++) {
        if (obj->sub[i]) {
            trieFree(obj->sub[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */
