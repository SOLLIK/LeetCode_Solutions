class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) {
            return 0;
        }

        int ans = 0;
        int counter = 1;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                continue;
            }
            if(nums[i - 1] + 1 == nums[i]) {
                counter++;
            }
            else{
                ans = max(ans, counter);
                counter = 1;
            }
        }
        return max(ans, counter);
    }
};