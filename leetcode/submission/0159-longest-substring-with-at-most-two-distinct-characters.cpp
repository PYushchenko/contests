class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> m;
        int left = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            if (m.size() > 2) {
                m[s[left]]--;
                if (m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left++;
            }
            if (i - left + 1 > max) {
                max = i - left + 1;
            } 
        }
        return max;
    }
};
