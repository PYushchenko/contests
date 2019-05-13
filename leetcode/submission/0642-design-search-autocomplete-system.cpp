class AutocompleteSystem {
public:
    
    
    class Trie {
        public:
        /** Initialize your data structure here. */

        class Node{
            public:
            class Node *child[27];
            int end = 0;
        };

        Node *root = NULL;

        Trie() {

        }

        /** Inserts a word into the trie. */
        void insert(string word, int count) {
            if (root == NULL)
                root = new Node();
            Node *p = root;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == ' ') {
                    if (p->child[26] == NULL) {
                        p->child[26] = new Node();
                    }
                    p = p->child[26];
                } else {
                    if (p->child[word[i] - 'a'] == NULL) {
                        p->child[word[i] - 'a'] = new Node();
                    }
                    p = p->child[word[i] - 'a'];
                }
            }
            p->end += count;
        }

        // /** Returns if the word is in the trie. */
        // bool search(string word) {
        //     if (root == NULL) {
        //         return false;
        //     }
        //     Node *p = root;
        //     for (int i = 0; i < word.size(); i++) {
        //         if (p->child[word[i] - 'a'] == NULL) {
        //             return false;
        //         } else {
        //             p = p->child[word[i] - 'a'];
        //         }
        //     }
        //     return p->end;
        // }
        
        vector<pair<string,int>> traverse(Node *p, string current) {
            vector<pair<string,int>> res;
            if (p->end != 0) {
                res.push_back({current, p->end});
            }
            for (int i = 0; i < 26; i++) {
                if (p->child[i]) {
                    auto tmp = traverse(p->child[i], current + (char) (i + 'a'));
                    res.insert(res.end(), tmp.begin(), tmp.end());
                }
            }
            if (p->child[26]) {
                auto tmp = traverse(p->child[26], current + " ");
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
            return res;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        vector<pair<string,int>> startsWith(string prefix) {
            if (root == NULL) {
                return {};
            }
            Node *p = root;
            for (int i = 0; i < prefix.size(); i++) {
                if (prefix[i] == ' ') {
                    if (p->child[26] == NULL) {
                        return {};
                    } else {
                        p = p->child[26];
                    }
                } else {
                    if (p->child[prefix[i] - 'a'] == NULL) {
                        return {};
                    } else {
                        p = p->child[prefix[i] - 'a'];
                    }
                }
            }
            return traverse(p, prefix);
        }
    };

    
    Trie st;
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); i++) {
            st.insert(sentences[i], times[i]);
        }
    }
    
    static bool startsWith(string s, string prefix) {
        if (prefix.size() > s.size()) return false;
        for (int i = 0; i < prefix.size(); i++) {
            if (s[i] != prefix[i]) {
                return false;
            }
        }
        return true;
    }
    
        // Compares two intervals according to staring times. 
    static bool compareInterval(pair<int, string> i1, pair<int, string> i2) 
    { 
        if (i1.first == i2.first) {
            return i1.second > i2.second;
        }
        return (i1.first < i2.first); 
    } 
    
    string current = "";
    
    vector<string> input(char c) {
        if (c == '#') {
            st.insert(current, 1);
            current = "";
            return vector<string>();
        }
        current += c;
        priority_queue<pair<int, string>,vector<pair<int,string>>, function<bool(pair<int, string>, pair<int, string>)>> heap(compareInterval);
        auto arr = st.startsWith(current);
        for (auto s : arr) {
            heap.push({s.second, s.first});
        }
            
        vector<string> res;
        while (heap.size() > 0 and res.size() < 3) {
            auto s = heap.top();
            res.push_back(s.second);
            heap.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
