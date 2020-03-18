#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
        }

    void insertWord(string word) {
        insert(root, word);
    }
    void insert(TrieNode *root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insert(child, word.substr(1));
    }

     void search(string word) {
        TrieNode* node = getNode(root, word);
        if(node != NULL)
            searchUsingPrefix(node, word);
        else 
            cout << word << " -> No other strings found with this prefix" << endl;
    }

    TrieNode* getNode(TrieNode *root, string word) {
        if(root == NULL)
            return NULL;
        
        if(word.size() != 0) {
            int index = word[0] - 'a';
            if(root -> children[index] != NULL)
                return getNode(root -> children[index], word.substr(1));
        }
        else
            return root;
        return NULL;
    }

    void searchUsingPrefix(TrieNode* node, string prefixWord) {
        if(node -> isTerminal) {
            cout <<  prefixWord << endl;
        }
        for(int i = 0; i < 26; i++) {
            if(node -> children[i] != NULL) {
                prefixWord += node -> children[i] -> data;
                searchUsingPrefix(node -> children[i], prefixWord);
                prefixWord.pop_back();
            }
        }
        return;
    }
};

int main() {
    Trie root;
    root.insertWord("dog");
    root.insertWord("deer");
    root.insertWord("deal");
    root.search("de");

    // root.insertWord("hello"); 
    // root.insertWord("dog"); 
    // root.insertWord("hell"); 
    // root.insertWord("cat"); 
    // root.insertWord("a"); 
    // root.insertWord("help"); 
    // root.insertWord("hel"); 
    // root.insertWord("helps"); 
    // root.insertWord("helping");

    // root.search("caty");
    return 0;
}