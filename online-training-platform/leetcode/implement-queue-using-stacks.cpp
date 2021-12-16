class MyQueue {
public:
    
    stack<int> first, second;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(!first.empty()) {
            second.push(first.top());
            first.pop();
        }
        
        int result = second.top();
        second.pop();
        
        while(!second.empty()) {
            first.push(second.top());
            second.pop();
        }
        
        return result;
    }
    
    int peek() {
        while(!first.empty()) {
            second.push(first.top());
            first.pop();
        }
        
        int result = second.top();
        
        while(!second.empty()) {
            first.push(second.top());
            second.pop();
        }
        
        return result;
    }
    
    bool empty() {
        return first.empty() && second.empty();
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