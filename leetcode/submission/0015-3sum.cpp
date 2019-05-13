class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right and nums[left] == nums[left + 1]) left++;
                    while (left < right and nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
        }
        // std::sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
