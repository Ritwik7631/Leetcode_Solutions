class MinStack {
public:
    stack<int> stk;
    stack<int> mn;
    int mini = INT_MAX;

    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        mini = min(mini, val);
        mn.push(mini);
        
    }
    
    void pop() {
        stk.pop();
        mn.pop();
        if(!mn.empty())
        {
            mini = mn.top();
        }
        else
        {
            mini = INT_MAX;
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */