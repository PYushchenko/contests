class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count = 0;
                if (i > 0 and (board[i - 1][j] == 1 or board[i - 1][j] == 3)) count++;
                if (i > 0 and j > 0 and (board[i - 1][j - 1] == 1 or board[i - 1][j - 1] == 3)) count++;
                if (j > 0 and (board[i][j - 1] == 1 or board[i][j - 1] == 3)) count++;
                if (i < n - 1 and (board[i + 1][j] == 1 or board[i + 1][j] == 3)) count++;
                if (i < n - 1 and j < m - 1 and (board[i + 1][j + 1] == 1 or board[i + 1][j + 1] == 3)) count++;
                if (j < m - 1 and (board[i][j + 1] == 1 or board[i][j + 1] == 3)) count++;
                if (i > 0 and j < m - 1 and (board[i - 1][j + 1] == 1 or board[i - 1][j + 1] == 3)) count++;
                if (i < n - 1 and j > 0 and (board[i + 1][j - 1] == 1 or board[i + 1][j - 1] == 3)) count++;
                // cout << count;
                if (board[i][j] == 1) {
                    if (count < 2) board[i][j] = 3;
                    if (count >= 2 and count <= 3) board[i][j] = 1;
                    if (count > 3) board[i][j] = 3;
                } else {
                    if (count == 3) board[i][j] = 2;
                    if (count != 3) board[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};
