class MinStack {
    typedef pair<int, int> pii;
private: 
    stack <pii> st, mn;
    int count;
public:

    MinStack() {
        this->count = 0;
    }
    
    void push(int val) {
        this->st.push({this->count, val});
        if (this->mn.empty() || val < this->mn.top().second)
            this->mn.push({this->count, val});
        this->count++;
    }
    
    void pop() {
        if (this->st.top().first == this->mn.top().first)
            this->mn.pop();
        this->st.pop();
        this->count--;
    }
    
    int top() {
        return this->st.top().second;
    }
    
    int getMin() {
        return this->mn.top().second;
    }
};