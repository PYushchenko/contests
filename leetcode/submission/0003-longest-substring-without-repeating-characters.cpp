class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> ss;
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < s.size()) {
            if (ss.find(s[right]) == ss.end()) {
                ss.insert(s[right]);
            } else {
                while (s[left] != s[right]) {
                    ss.erase(s[left]);
                    left++;
                }
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
