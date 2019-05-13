class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int res = 0;
        
        
        vector<int> dp = vector<int>(n, 0);
        
        int l = 0;
        
        for (int i = 0; i < n; i++) {
            l += sentence[i].size() + 1;
        }
        
        int total = (cols + 1) / l;
        int x = total * l;
        cout << total << " " << x << endl;
        for (int i = 0; i < n; i++) {
            if (x == cols + 1) {
                dp[i] = total * n;
            } else {
                int pos = i;
                int y = x;
                dp[i] = total * n + pos;
                while (y + sentence[pos].size() <= cols) {
                    y += sentence[pos].size() + 1;
                    pos++;
                    if (pos >= sentence.size()) {
                        pos = 0;
                    }
                    dp[i]++;
                }
            }
        }
            
        // for (int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        int y = 0;
        int pos = 0;
        while (y < rows) {
            pos = dp[pos];
            res += pos / n;
            pos %= n;
            y++;
        }
        return res;
    }
};
