class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
       int n = nums.size();
       if(n==1) return true;
       int c=0;
       for(int i=1; i<n; i++) {
        if(nums[i-1]%2!=nums[i]%2) c++;
       }

       if(c==n || c==n-1) return true;
       return false;
    }
};