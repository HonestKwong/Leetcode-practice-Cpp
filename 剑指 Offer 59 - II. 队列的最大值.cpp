class MaxQueue {
private:
    deque<int> que;
    deque<int> ast;
public:
    MaxQueue() {

    }
    
    int max_value() {
        int tmp = -1;
        if(ast.empty()) return -1;
        else 
            tmp = ast.front();
        return tmp;
    }
    
    void push_back(int value) {
        que.push_back(value);
        if(ast.empty()){
            ast.push_back(value);
            return;
        }
        if(value>ast.back()){
            for(auto &x : ast) 
                if(x<value) x = value;
            
            // for(int i=0; i<ast.size(); i++) ast[i] = value;
            ast.push_back(value);
        }
        else ast.push_back(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int tmp = que.front();
        que.pop_front();
        ast.pop_front();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */