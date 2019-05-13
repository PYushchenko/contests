class Solution {
public:
    vector<string> res;
    
    void removePr(string s, int left, int left_rm, char lb, char rb) {
        int counter = 0;
        for (int i = left; i < s.size(); i++) {
            if (s[i] == lb) counter++;
            if (s[i] == rb) counter--;
            if (counter < 0) {
                for (int j = left_rm; j <= i; j++) {
                    if (s[j] == rb and (j == 0 or s[j - 1] != rb)) {
                        string copy = s;
                        copy.erase(j, 1);
                        removePr(copy, left, j, lb, rb);
                    }
                }
            } else {
                continue;
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (lb == ')') {
            res.push_back(s);
        } else {
            removePr(s, 0, 0, rb, lb);
        }
    }
        
    vector<string> removeInvalidParentheses(string s) {
        removePr(s, 0, 0, '(', ')');
        return res;
    }
};
