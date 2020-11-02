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
    int recur(TreeNode* root){
        if(root == NULL) return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        if(left==-1 || right==-1) return -1;
        else if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return recur(root)!=-1;
    }
};