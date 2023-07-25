class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.isEndOfWord = True

    def search(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
        return node.isEndOfWord

    def startsWith(self, prefix):
        node = self.root
        for c in prefix:
            if c not in node.children:
                return False
            node = node.children[c]
        return True

# Test the Trie
trie = Trie()
trie.insert("apple")
trie.insert("app")
trie.insert("banana")

print("Search 'apple':", trie.search("apple"))         # Output: True
print("Search 'app':", trie.search("app"))             # Output: True
print("Search 'orange':", trie.search("orange"))       # Output: False
print("StartsWith 'app':", trie.startsWith("app"))     # Output: True
print("StartsWith 'ora':", trie.startsWith("ora"))     # Output: False

Time Complexities:

Insertion: O(m), where m is the length of the word being inserted.
Search: O(m), where m is the length of the word being searched.
StartsWith: O(m), where m is the length of the prefix being searched.

Space Complexity:

The space complexity of the Trie is O(N * M),
where N is the number of words in the Trie and M is the average length of the words.
This is because each node in the Trie requires memory for its children (dictionary)
and the isEndOfWord boolean flag.
