class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = 0;
        int n =  nums.size();
        int res = INT_MIN;
        int sum = 0;
        while (right < n) {
            sum += nums[right];
            res = max(res, sum);
            sum = max(0, sum);
            right++;
        }
        return res;
    }
};
