class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs(int(s.size()) - int(t.size())) > 1) return false;
        int diff = 0;
        int i = 0;
        int j = 0;
        while (i < s.size() and j < t.size()) {
            if (s[i] != t[j]) {
                if (s.size() < t.size()) {
                    j++;
                } else if (s.size() > t.size()) {
                    i++;
                } else {
                                i++;
            j++;
                }
                diff++;
            } else {
                            i++;
            j++;
            }
            if (diff > 1) {
                return false;
            }
        }
        if (diff == 0 and abs(int(s.size()) - int(t.size())) == 1) return true;
        return diff == 1;
    }
};
