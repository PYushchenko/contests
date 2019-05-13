class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        int s_c[10] = {0};
        int g_c[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                s_c[secret[i] - '0']++;
                g_c[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i ++) {
            cow += min(s_c[i], g_c[i]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
