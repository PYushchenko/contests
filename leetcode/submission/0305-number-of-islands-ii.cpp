class Solution {
public:
    int find_root(vector<int> &root, int i) {
        if (root[i] != i) root[i] = find_root(root, root[i]);
        return root[i];
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> root = vector<int>(n * m, -1);
        vector<int> rank = vector<int>(n * m, 0);
        int island_id = 0;
        int num_island = 0;
        
        vector<int> res;
        
        for (auto pos: positions) {
            int x = pos.first;
            int y = pos.second;
            vector<int> overlap;
            if (x > 0 && root[(x - 1) * n + y] != -1) overlap.push_back((x - 1) * n + y);
            if (x + 1 < m && root[(x + 1) * n + y] != -1) overlap.push_back((x + 1) * n + y);
            if (y > 0 && root[x * n + y - 1] != -1) overlap.push_back(x * n + y - 1);
            if (y + 1 < n && root[x * n + y + 1] != -1) overlap.push_back(x * n + y + 1);
            
            if (overlap.size() == 0) {
                num_island++;
                root[x * n + y] = x * n + y;
            } else if (overlap.size() == 1) {
                root[x * n + y] = root[overlap[0]];
            } else {
                num_island++;
                root[x * n + y] = x * n + y;
                int j = x * n + y;
                
                for (auto i : overlap) {
                    //overlap i and j
                    int root_i = find_root(root, i);
                    int root_j = find_root(root, j);
                    if (root_i != root_j) {
                        if (rank[root_i] > rank[root_j]) {
                            root[root_j] = root_i;
                        } else if (rank[root_i] < rank[root_j]) {
                            root[root_i] = root_j;
                        } else {
                            root[root_j] = root_i; rank[root_i] += 1;
                        }
                        num_island--;
                    }
                }
            }
            res.push_back(num_island);
        }        
        return res;
    }
};
