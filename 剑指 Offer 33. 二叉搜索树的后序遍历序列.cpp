class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        //递归分治
        return recur(postorder, 0, postorder.size()-1);

    }
    bool recur(vector<int>& tmporder, int i, int j){
        if(i>=j) return true;
        
        int p = i;
        while(tmporder[p]<tmporder[j]) p++;
        int m = p;
        while(tmporder[p]>tmporder[j]) p++;
        return p==j && recur(tmporder, i, m-1) && recur(tmporder,m,j-1);   //后面为什么是-1？
        
    }
};


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> tmp_stack;
        int root = INT_MAX;
        for(int i = postorder.size()-1; i>=0; i--){
            if(postorder[i]>root) return false;
            while(!tmp_stack.empty()&&(postorder[i]<tmp_stack.top())){
                root = tmp_stack.top();
                tmp_stack.pop();
            }

            tmp_stack.push(postorder[i]);
        }
        return true;
    }
};