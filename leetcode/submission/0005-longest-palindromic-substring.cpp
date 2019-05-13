class Solution {
public:
    int testPalin(const string & s, int left, int right) {
        while (left >=0 and right < s.size() and s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int res_left = 0, res_right = 0;
        for (int i = 0; i < n; i ++) {
            int tmp = testPalin(s, i, i);
            if (tmp > res_right - res_left) {
                res_left = i - (tmp - 1) / 2;
                res_right = i + tmp / 2;
            }
            tmp = testPalin(s, i, i + 1);
            if (tmp > res_right - res_left) {
                res_left = i - (tmp - 1) / 2;
                res_right = i + tmp / 2;
            }
        }
        return s.substr(res_left, res_right - res_left + 1);
    }
};
