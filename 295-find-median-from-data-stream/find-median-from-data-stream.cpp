class MedianFinder {
    priority_queue<int> sH; 
    priority_queue<int, vector<int>, greater<int>> lH;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (sH.empty() || sH.top() > num) {
            sH.push(num);
        }
        else {
            lH.push(num);
        }
        if (sH.size() > lH.size() + 1) {
            lH.push(sH.top());
            sH.pop();
        }
        else if (lH.size() > sH.size() + 1) {
            sH.push(lH.top());
            lH.pop();
        }
    }

    double findMedian() {
        if (sH.size() == lH.size()) return sH.empty() ? 0 : ((lH.top() + sH.top()) / 2.0);
        else return (sH.size() > lH.size()) ? sH.top() : lH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */