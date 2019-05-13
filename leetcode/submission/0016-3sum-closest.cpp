class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 1000000;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target-sum)<abs(target-closest)) {
                   closest = sum;
                }
                if (sum - target > 0) {
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
        return closest;
    }
};
