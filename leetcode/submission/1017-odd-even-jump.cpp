class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<bool> odd = vector<bool>(A.size(), false);
        vector<bool> even = vector<bool>(A.size(), false);
        odd[A.size() - 1] = true;
        even[A.size() - 1] = true;
        map<int, int> jump_map;
        jump_map.insert({A[A.size() - 1], A.size() - 1});
        for (int i = A.size() - 2; i >= 0; i-- ) {
            auto it = jump_map.find(A[i]);
            if (it != jump_map.end()) {
                odd[i] = even[it->second];
                even[i] = odd[it->second];
                jump_map.erase(it);
            } else {
                auto gt = jump_map.upper_bound(A[i]);
                auto lt = jump_map.lower_bound(A[i]);
                if (lt == jump_map.begin()) {
                    lt = jump_map.end();
                } else {
                    lt--;
                }
                if (gt != jump_map.end()) {
                    odd[i] = even[gt->second];
                }
                if (lt != jump_map.end()) {
                    even[i] = odd[lt->second];
                }
            }
            jump_map.insert({A[i], i});
        }
        int count = 0;
        for (auto i: odd) {
            if (i) count++;
        }
        return count;
    }
};
