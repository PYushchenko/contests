class Solution {
public:
    unordered_map<int, int> m;
    int totalFruit(vector<int>& tree) {
        int max = 0;
        int left = 0;
        
        for (int i = 0; i < tree.size(); i++) {
            m[tree[i]]++;
            while (m.size() > 2) {
                m[tree[left]]--;
                if (m[tree[left]] == 0) {
                    m.erase(tree[left]);
                }
                left++;
            }
            if ((i - left + 1) > max) {
                max = i - left + 1;
            }
        }
        return max;
    }
};
