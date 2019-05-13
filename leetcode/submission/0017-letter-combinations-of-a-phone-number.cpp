class Solution {
public:
    
    void generate(string &s, vector<string> &res, int pos, string &digits) {
        if (pos == digits.size()) {
            res.push_back(s);
        } else {
            if (digits[pos] == '2') {
                s[pos] = 'a';
                generate(s, res, pos + 1, digits);
                s[pos] = 'b';
                generate(s, res, pos + 1, digits);
                s[pos] = 'c';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '3') {
                s[pos] = 'd';
                generate(s, res, pos + 1, digits);
                s[pos] = 'e';
                generate(s, res, pos + 1, digits);
                s[pos] = 'f';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '4') {
                s[pos] = 'g';
                generate(s, res, pos + 1, digits);
                s[pos] = 'h';
                generate(s, res, pos + 1, digits);
                s[pos] = 'i';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '5') {
                s[pos] = 'j';
                generate(s, res, pos + 1, digits);
                s[pos] = 'k';
                generate(s, res, pos + 1, digits);
                s[pos] = 'l';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '6') {
                s[pos] = 'm';
                generate(s, res, pos + 1, digits);
                s[pos] = 'n';
                generate(s, res, pos + 1, digits);
                s[pos] = 'o';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '7') {
                s[pos] = 'p';
                generate(s, res, pos + 1, digits);
                s[pos] = 'q';
                generate(s, res, pos + 1, digits);
                s[pos] = 'r';
                generate(s, res, pos + 1, digits);
                s[pos] = 's';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '8') {
                s[pos] = 't';
                generate(s, res, pos + 1, digits);
                s[pos] = 'u';
                generate(s, res, pos + 1, digits);
                s[pos] = 'v';
                generate(s, res, pos + 1, digits);
            }
            if (digits[pos] == '9') {
                s[pos] = 'w';
                generate(s, res, pos + 1, digits);
                s[pos] = 'x';
                generate(s, res, pos + 1, digits);
                s[pos] = 'y';
                generate(s, res, pos + 1, digits);
                s[pos] = 'z';
                generate(s, res, pos + 1, digits);

            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        int pos = 0;
        string s = string(digits.size(), ' ');
        vector<string> res;
        generate(s, res, pos, digits);
        return res;
    }
};
