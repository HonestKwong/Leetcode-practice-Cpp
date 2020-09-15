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
//运行效率还不错，93%
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;   //空二叉树也是对称的？
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* right, TreeNode*left){
        if(right == NULL&&left ==NULL) return true;
        else if(right == NULL||left ==NULL) return false;
        return (left->val==right->val)&&isMirror(left->left,right->right)&&isMirror(left->right,right->left);  //先查左左右右，再插左右和右左

    }
};