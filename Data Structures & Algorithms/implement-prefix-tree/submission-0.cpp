class PrefixTree {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {children[i] = nullptr;}
        }
    };

    TrieNode* root;

    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {clear(node->children[i]);}
        delete node;
    }

public:
    PrefixTree() {root = new TrieNode();}

    ~PrefixTree() {clear(root);}
    
    void insert(string word) {
        TrieNode* curr = root;

        for (auto &ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {curr->children[idx] = new TrieNode();}
            curr = curr->children[idx];
        }

        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (auto &ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }

        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (auto &ch : prefix) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }

        return true;
    }
};