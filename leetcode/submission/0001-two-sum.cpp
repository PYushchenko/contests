class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for (int i = 0; i < nums.size(); i++) {
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());
        int right = nums.size() - 1;
        for (int i = 0; i < right; i++) {
            while (a[i].first + a[right].first > target and right > i) 
                right--;
            if (a[i].first + a[right].first == target) {
                cout << nums[i] <<"+"<< nums[right];
                return {a[i].second, a[right].second};
            }
        }
        return {};
    }
};
