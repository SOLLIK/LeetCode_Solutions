class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    int k;
public:
    void minHeap(int val) {
        MinHeap.push(val);
        if(MinHeap.size() > k) {
            MinHeap.pop();
        }
    }

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            minHeap(num);
        }
    }
    
    int add(int val) {
        minHeap(val);
        return MinHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */