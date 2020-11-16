/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
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
    bool isValidBST(TreeNode* root) {
        // if(root == NULL) return true;
        return isValidSubBST(root, NULL, NULL);
       
    }
    bool isValidSubBST(TreeNode* root, TreeNode* min, TreeNode* max)  {
        if(root == NULL) return true;
        if(min!=NULL && root->val <= min->val) return false;
        if(max!=NULL && root->val >= max->val) return false;
        // if(root->left->val < root->val && root->left > min){
        // }
        // if(root->right->val > root->val && root->right <max){           
        // }
        return isValidSubBST(root->left,min,root) && isValidSubBST(root->right,root,max);

    }
};


// @lc code=end

