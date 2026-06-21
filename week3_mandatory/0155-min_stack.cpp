class MinStack {
    stack <int> v,m;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        v.push(value);
        if(m.empty()){
            m.push(value);
        } else {
            if(m.top()>=value){
                m.push(value);
            }
        }
    }
    
    void pop() {
        if(v.top()==m.top()){
            m.pop();
        }
        v.pop();
    }
    
    int top() {
        return v.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
