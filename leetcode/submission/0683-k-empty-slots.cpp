class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> active = set<int>();
        int i = 0;
        for (auto x : flowers) {
            i++;
            active.insert(x);
            auto lower = active.lower_bound(x);
            auto upper = active.upper_bound(x);
            lower--;
            if (lower != active.end() and (x - *lower - 1) == k) {
                return  i;
            }
            if (upper != active.end() and (*upper - x - 1) == k) {
                return  i;
            }
        }
        return -1;
    }
};
