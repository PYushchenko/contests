class Solution {
public:
    string decode(string &s, int &pos) {
        if (pos >= s.size()) return "";
        if (isdigit(s[pos])) {
            string counts;
            while (isdigit(s[pos])) {
                counts += s[pos++];
            }
            int count = stoi(counts);
            pos++;
            string data = decode(s, pos);
            string res = "";
            for (int i = 0; i < count; i++) {
                res += data;
            }
            return res + decode(s, pos);
        } else {
            string data;
            while (pos < s.size() and isalpha(s[pos])) {
                data += s[pos++];
            }
            if (s[pos] == ']') {
                pos++;
                return data;
            }
            return data + decode(s, pos);
        }
        
    }
    
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }
};
