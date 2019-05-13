class Solution {
public:
    string readtoken(const string &s, int &pos) {
        string res;
        while (s[pos] != ' ' and s[pos] != ')') {
            res += s[pos++];
        }
        return res;
    }
    
    int ev(const string &s, map<string, int> v, int &pos) {
        pos++;//skipping (
        string type = "";
        int res = 0;
        if (s[pos] == 'l') {
            type = "let";
            pos += 4;
        } else
        if (s[pos] == 'a') {
            type = "add";
            pos += 4;
            res = 0;
        } else
        if (s[pos] == 'm') {
            type = "mult";
            pos += 5;
            res = 1;
        }
        while(s[pos] != ')') {
            if (type == "let") {
                if (s[pos] == '(') {
                    res = ev(s, v, pos);
                } else {
                    string q = readtoken(s, pos);
                    if (s[pos] != ')') {
                        pos++;
                        int tmp;
                        if (s[pos] >= '0' and s[pos] <='9' or s[pos] == '-') {
                            tmp = stoi(readtoken(s, pos));
                        } else if (s[pos] == '(') {
                            tmp = ev(s, v, pos);
                        } else {
                            tmp = v[readtoken(s, pos)];
                        }
                        v[q] = tmp;
                    } else {
                        if (q[0] >= '0' and q[0] <='9' or q[0] == '-') {
                            res = stoi(q);
                        } else {
                            res = v[q];
                        }
                    }
                }
            } else {
                int tmp;
                if (s[pos] >= '0' and s[pos] <='9' or s[pos] == '-') {
                    tmp = stoi(readtoken(s, pos));
                } else if (s[pos] == '(') {
                    tmp = ev(s, v, pos);
                } else {
                    tmp = v[readtoken(s, pos)];
                }
                if (type == "mult") {
                    res *= tmp;
                } else {
                    res +=  tmp;
                }
            }
            if (s[pos] == ')') {
                pos++;
                break;
            }
            pos++;
        }
        return res;
    }
    
    int evaluate(string expression) {
        int pos = 0;
        return ev(expression, map<string, int>(), pos);
    }
};
