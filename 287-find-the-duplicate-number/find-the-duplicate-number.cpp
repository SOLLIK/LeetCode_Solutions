class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0;
        while(nums[s] != nums[nums[s]]) {
            swap(nums[s], nums[nums[s]]);
        }
        return nums[s];
    }
};