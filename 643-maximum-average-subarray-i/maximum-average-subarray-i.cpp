class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
            
       double current = 0;
        double max = 0;

        for (int i = 0; i < k; i++) {
            current += nums[i];
        }

        max = current;

        for (int i = k; i < nums.size(); i++) {
            current += nums[i] - nums[i - k];

            if (current > max ) {
                max = current;
            }
        }

        return max / k;	
	
    }
};