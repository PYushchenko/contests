class Solution {
public:
    int dotype(int &a, int &b, char &type) {
        if (type == '+') {
            return a + b;
        } else if (type == '-'){
            return a - b;
        }
        return 0;
    }
    
    int calculate(const string &s, int &pos) {
        char type = '_';
        int res = 0;
        int a = 0;
        int tmp = 0;
        bool number = false;
        for (; pos < s.size(); pos++) {
            char c = s[pos];
            if (c == '(') {
                number = true;
                pos++;
                tmp = calculate(s, pos);
            } else if (c >= '0' and c <= '9') {
                number = true;
                tmp = tmp * 10 + (c - '0');
            } else if (c == '+' or c == '-') {
                if (type == '_' and number) {
                    a = tmp;
                } else if (number) {
                    a = dotype(a, tmp, type);
                }
                number = false;
                tmp = 0;
                type = c;
            } else if (c == ')') {
                if (type == '_' and number) {
                    a = tmp;
                } else if (number) {
                    a = dotype(a, tmp, type);
                }
                cout << "<" <<a;
                return a;
            } else {
            }
        }
        cout << "|" << a << "," <<tmp;
        if (type == '_') {
            a = tmp;
        } else {
            a = dotype(a, tmp, type);
        }
        return a;
    }
    
    int calculate(string s) {
        int pos = 0; 
        return calculate(s, pos);
    }
};
