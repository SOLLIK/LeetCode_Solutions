class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> m;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto g : nums) {
            m.push(g);
            if(m.size() > n) {
                m.pop();
            }
        }
    }
    
    int add(int val) {
        m.push(val);
        if(m.size() > n) {
            m.pop();
        }
        return m.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */