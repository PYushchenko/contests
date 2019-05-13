class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> m;
        int max = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            while (m.size() > k) {
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
