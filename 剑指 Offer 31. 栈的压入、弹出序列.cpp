class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> simulation_stack;
        // const int length = pushed.size();
        int i = 0;
        for(int x:pushed){
            simulation_stack.push(x);
            // while 循环时判断的关键：这里要根据栈中已有的判断是否
            while(!simulation_stack.empty() && simulation_stack.top()==popped[i]){  
                simulation_stack.pop();
                i++;
            }
        }
        // while(i<pushed.size()){
        //     simulation_stack.pop();
        // }
        if(simulation_stack.empty()) return true;
        return false;
    }
};