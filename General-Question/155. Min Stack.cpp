class MinStack {
private:
    struct Node {
        int val;
        int min;
    };
    
    vector<Node> stack;
public:
    /** initialize your data structure here. */
    
    MinStack() {
        stack.clear();
    }
    
    void push(int x) {
        int size = stack.size();
        Node push;
        push.val = x;
        if(size != 0){
            Node top = stack[size - 1];
            if(top.val < push.val){
                push.min = top.min;
            }else{
                if(push.val < top.min){
                    push.min = push.val;    
                }else{
                    push.min = top.min;
                }
                
            }
            
        }else{
            push.min = x;
        }
        
        stack.push_back(push);
    }
    
    void pop() {
        int size = stack.size();
        if(size != 0){
            stack.erase(stack.end() - 1);    
        }
    }
    
    int top() {
        int size = stack.size();
        if(size != 0) return stack[size - 1].val;
        return -1;
    }
    
    int getMin() {
        
        int size = stack.size();
        
        if(size != 0) return stack[size - 1].min;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */