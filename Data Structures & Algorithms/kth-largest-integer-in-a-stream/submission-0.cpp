class KthLargest {
public:
    priority_queue <int, vector <int>, greater <int> > minheap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            this->minheap.push(num);
            if (this->minheap.size() > k)
                this->minheap.pop();
        }
    }
    
    int add(int val) {
        this->minheap.push(val);
        if (this->minheap.size() > k)
            this->minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */