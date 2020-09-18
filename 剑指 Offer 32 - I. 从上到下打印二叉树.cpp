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
    vector<int> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> queue1;
        vector<int> res;
        queue1.push(root);
        while(!queue1.empty()){
            TreeNode* node = queue1.front();
            res.push_back(node->val);
            if(node->left != NULL) queue1.push(node->left);
            if(node->right != NULL) queue1.push(node->right);
            queue1.pop();
        }
        return res;
    }
};