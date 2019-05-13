class Trie {
public:
    /** Initialize your data structure here. */
    
    class Node{
        public:
        class Node *child[26];
        bool end = false;
    };
    
    Node *root = NULL;
    
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (root == NULL)
            root = new Node();
        Node *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == NULL) {
                p->child[word[i] - 'a'] = new Node();
            }
            p = p->child[word[i] - 'a'];
        }
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (root == NULL) {
            return false;
        }
        Node *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->child[word[i] - 'a'] == NULL) {
                return false;
            } else {
                p = p->child[word[i] - 'a'];
            }
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (root == NULL) {
            return false;
        }
        Node *p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->child[prefix[i] - 'a'] == NULL) {
                return false;
            } else {
                p = p->child[prefix[i] - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
