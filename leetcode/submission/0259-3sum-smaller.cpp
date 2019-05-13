class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                   count += right -left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        // std::sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return count;
        
    }
};
