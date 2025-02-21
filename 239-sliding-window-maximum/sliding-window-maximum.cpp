class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; //idx
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            while(q.size()>0 && q.front()<i-k+1) q.pop_front();
            while(q.size()>0 && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);

            if(i+1>=k){ // window has started
                ans.push_back(nums[q.front()]);
            } 
        }
        return ans;
    }
};
