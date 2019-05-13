class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 and nums[i] >= nums[i + 1]) i--;        //find position to swap;
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i and nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        // return nums;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int count = 1;
        for (int i = 1; i <= nums.size(); i++) count *= i;
        for (int i = 0; i < count; i++) {
            res.push_back(nums);
            nextPermutation(nums);
        }
        return res;
    }
};
