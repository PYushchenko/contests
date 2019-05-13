class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string a = A;
        int q = 1;
        while (a.size() < B.size()) {
            a += A;
            q++;
        }
        if (a.find(B) != string::npos) {
            return q;
        } else {
            a += A;
            q++;
            if (a.find(B) != string::npos) {
                return q;
            }
        }
        return -1;
    }
};
