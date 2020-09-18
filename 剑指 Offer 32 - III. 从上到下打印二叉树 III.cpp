/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//关于这道题，我觉得一个比较难的点在于，如何找出其中哪些节点为一层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return{};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        int count = 1;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
//下面这个for循环可以分层
            for(int i = que.size();i>0;i--){
                tmp.push_back(que.front()->val);
                if(que.front()->left!=NULL) que.push(que.front()->left);
                if(que.front()->right!=NULL) que.push(que.front()->right);
                que.pop();
            }
            if(!(count%2)){
                reverse(tmp.begin(),tmp.end());     
            }    
            res.push_back(tmp); 
            count++;       
        }
        return res;
    }
};