class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (x > 0 and grid[x - 1][y] == '1')
            dfs(grid, visited, x - 1, y);
        if (x < grid.size() - 1 and grid[x + 1][y] == '1')
            dfs(grid, visited, x + 1, y);
        if (y > 0 and grid[x][y - 1] == '1')
            dfs(grid, visited, x, y - 1);
        if (y < grid[0].size() - 1 and grid[x][y + 1] == '1')
            dfs(grid, visited, x, y + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j] == false and grid[i][j] == '1') {
                    res++;
                    dfs(grid, visited, i, j);
                }
            }
        } 
        return res;
    }
};
