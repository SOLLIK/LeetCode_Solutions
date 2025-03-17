class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            MinHeap.push(num);
            if(MinHeap.size() > k) {
                MinHeap.pop();
            }
        }
    }
    
    int add(int val) {
        MinHeap.push(val);
        if(MinHeap.size() > k) {
            MinHeap.pop();
        }
        return MinHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */