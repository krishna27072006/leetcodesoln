class MinStack {
private:
    stack<int> st;    
    int mini=INT_MAX;
    stack<int> m;

public:
    MinStack() {
        mini=INT_MAX;
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mini=val;
        }
        else if(val<=mini) {
            m.push(mini);
            mini = val;
        }
        
        st.push(val);
    }
    
    void pop() {
        if(st.top()==mini){
            if(!m.empty()){
                
                mini=m.top();
                m.pop();
            }
        }

        st.pop();     
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return mini;

        
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