class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        assist_stack.push(x);
        if(min_stack.empty()) min_stack.push(x);
        else if (x>min_stack.top()){
            min_stack.push(min_stack.top());
        } 
        else min_stack.push(x);
    }
    
    void pop() {
        assist_stack.pop();
        min_stack.pop();

    }
    
    int top() {
        return assist_stack.top();
    }
    
    int min() {
        return min_stack.top();

    }
private:
    stack<int> min_stack;
    stack<int> assist_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */