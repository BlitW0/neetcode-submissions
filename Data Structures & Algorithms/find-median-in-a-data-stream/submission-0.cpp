class MedianFinder {
    priority_queue <int> sh; // smaller half
    priority_queue <int, vector <int>, greater <> > lh; // larger half
public:
    MedianFinder() {}
    
    void addNum(int num) {
        sh.push(num);
        if (not lh.empty() and sh.top() > lh.top()) {
            lh.push(sh.top());
            sh.pop();
        }

        // rebalance to maintain sizes with diff atmost 1
        if (sh.size() > lh.size() + 1) {
            lh.push(sh.top());
            sh.pop();
        }
        if (lh.size() > sh.size() + 1) {
            sh.push(lh.top());
            lh.pop();
        }
    }
    
    double findMedian() {
        if (lh.size() == sh.size())
            return (lh.top() + sh.top()) / 2.0;
        return lh.size() > sh.size() ? lh.top() : sh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */