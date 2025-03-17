class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> mh;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto num : nums) {
            mh.push(num);
            if(mh.size() > n) {
                mh.pop();
            }
        }
    }
    
    int add(int val) {
        mh.push(val);
        if(mh.size() > n) {
            mh.pop();
        }
        return mh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */