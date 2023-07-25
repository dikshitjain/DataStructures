#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    std::cout << "Search 'apple': " << trie.search("apple") << std::endl;      // Output: 1 (true)
    std::cout << "Search 'app': " << trie.search("app") << std::endl;          // Output: 1 (true)
    std::cout << "Search 'orange': " << trie.search("orange") << std::endl;    // Output: 0 (false)
    std::cout << "StartsWith 'app': " << trie.startsWith("app") << std::endl;  // Output: 1 (true)
    std::cout << "StartsWith 'ora': " << trie.startsWith("ora") << std::endl;  // Output: 0 (false)

    return 0;
}


Time Complexities:

Insertion: O(m), where m is the length of the word being inserted.
Search: O(m), where m is the length of the word being searched.
StartsWith: O(m), where m is the length of the prefix being searched.

Space Complexity:

The space complexity of the Trie is O(N * M),
where N is the number of words in the Trie and M is the average length of the words.
This is because each node in the Trie requires memory for its children (unordered_map)
and the isEndOfWord boolean flag.
