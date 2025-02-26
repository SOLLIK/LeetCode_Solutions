class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        while(nums[s] != nums[nums[s]]) {
            swap(nums[s], nums[nums[s]]);
        }
        return nums[s];
    }
};