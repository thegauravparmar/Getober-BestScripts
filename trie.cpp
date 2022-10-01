// trie class implementation.
#include <bits/stdc++.h>
using namespace std;

class Trie {
   public:
    Trie* child[26];  // for 26 diff childs.
    bool end;
    Trie() {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
        end = false;
    }

    void insert(string word) {
        if (!word.size()) return;
        Trie* current = child[word[0] - 'a'];
        if (current == nullptr) current = new Trie();
        child[word[0] - 'a'] = current;
        for (int i = 1; i < word.size(); i++) {
            if (current == nullptr) current = new Trie();
            if (!current->child[word[i] - 'a']) {
                current->child[word[i] - 'a'] = new Trie();
            }
            current = current->child[word[i] - 'a'];
        }
        current->end = true;
    }

    bool search(string word) {
        if (!word.size()) return true;
        Trie* current = child[word[0] - 'a'];
        if (current == nullptr) return false;
        for (int i = 1; i < word.size(); i++) {
            if (!current->child[word[i] - 'a']) {
                return false;
            }
            current = current->child[word[i] - 'a'];
        }
        return current->end;
    }

    bool startsWith(string word) {
        if (!word.size()) return true;
        Trie* current = child[word[0] - 'a'];
        if (current == nullptr) return false;
        for (int i = 1; i < word.size(); i++) {
            if (!current->child[word[i] - 'a']) {
                return false;
            }
            current = current->child[word[i] - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    trie->search("apple");    // return True
    trie->search("app");      // return False
    trie->startsWith("app");  // return True
    trie->insert("app");
    trie->search("app");  // return True
}
