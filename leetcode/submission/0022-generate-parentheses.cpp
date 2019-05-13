class Solution {
public:
    void generate(vector<string> & res, string &s, int pos, int lb, int rb) {
        if (pos == s.size()) {
            res.push_back(s);
            return;
        }
        
        if (lb < s.size() / 2) {
            s[pos] = '(';
            generate(res, s, pos + 1, lb + 1, rb);
        }
        if (rb < lb) {
            s[pos] = ')';
            generate(res, s, pos + 1, lb, rb + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = string(n * 2, ' ');
        generate(res, cur, 0, 0, 0);
        return res;
    }
};
