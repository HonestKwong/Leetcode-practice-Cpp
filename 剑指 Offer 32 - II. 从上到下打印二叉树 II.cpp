/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return{};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            for (int i=que.size(); i>0; i--){  //初始条件进入队列，当前层保存的数量，非常有用
                tmp.push_back(que.front()->val);  
                if(que.front()->left!=NULL) que.push(que.front()->left);
                if(que.front()->right!=NULL) que.push(que.front()->right);
                que.pop();
            }
            res.push_back(tmp);
            
        }
        return res;
    }
};