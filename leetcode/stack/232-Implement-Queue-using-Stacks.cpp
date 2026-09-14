class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    void ops(stack<int>&st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        else{
            int a = st.top();
            st.pop();
            ops(st,x);
            st.push(a);
            return;
        }

    }
    
    void push(int x) {
        ops(st,x);
        
    }
    
    int pop() {
        int x= st.top();
        st.pop();
        return x;
        

        
    }
    
    int peek() {
        return st.top();
        
    }
    
    bool empty() {
        return st.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */