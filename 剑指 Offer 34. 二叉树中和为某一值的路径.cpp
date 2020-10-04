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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        recur(root, sum);
        return res;
    }

    void recur(TreeNode* root, int target){
        if(root == NULL) return;
        path.push_back(root->val);
        target -= root->val;
        if(target==0 && root->left==NULL&&root->right==NULL) 
            res.push_back(path);
        recur(root->left,target);
        recur(root->right,target);
        path.pop_back();  //难以理解？回退时去除当前路径的值
    }
};