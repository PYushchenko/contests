class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 or matrix[0].size() == 0) {
            return vector<int>();
        }
        vector<int> res;
        int rows = 0;
        int cols = 0;
        int dir = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while (count != matrix[0].size() * matrix.size()) {
            res.push_back(matrix[j][i]);
            count++;
            if (dir == 0) {
                if (i < matrix[0].size() - cols - 1) {
                    i++;
                } else {
                    dir = 1;
                    j++;
                }
            } else if (dir == 1) {
                if (j < matrix.size() - rows - 1) {
                    j++;
                } else {
                    dir = 2;
                    i--;
                }
            } else if (dir == 2) {
                if (i > cols) {
                    i--;
                } else {
                    dir = 3;
                    j--;
                    rows++;
                }
            } else if (dir == 3) {
                if (j > rows) {
                    j--;
                } else {
                    dir = 0;
                    i++;
                    cols++;
                }
            }
        }
        return res;
    }
};
