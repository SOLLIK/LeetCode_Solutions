class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> results(nums.size());
        results[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            results[i] = nums[i] + results[i - 1];
        }
        return results;
    }
};