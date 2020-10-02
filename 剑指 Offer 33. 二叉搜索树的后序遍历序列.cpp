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