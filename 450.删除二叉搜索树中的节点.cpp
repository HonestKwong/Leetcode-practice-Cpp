/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode-cn.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    25.2K
 * Total Submissions: 56.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 
 * 一般来说，删除节点可分为两个步骤：
 * 
 * 
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 * 
 * 
 * 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
 * 
 * 示例:
 * 
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            //这里要进行删改;
            if(root->left==NULL && root->right ==NULL) {
                return NULL;
            }
            else if(root->right == NULL && root->left!=NULL) return root->left;
            else if(root->right != NULL && root->left==NULL) return root = root->right;

            // else if(root->right == NULL && root->left!=NULL) root = root->left;
            // else if(root->right != NULL && root->left==NULL) root = root = root->right;
            else{
                auto tmp = root;
                auto pre = tmp;
                tmp = tmp->right;
                int count = 0;
                while(tmp->left!=NULL) {
                    count++;
                    pre = tmp;
                    tmp = tmp->left;
                    }
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
                // if(count) pre->left = NULL;
                // else pre->right =NULL;
                // auto tmp = findMin(root);
                // root->val = tmp->val;
                // tmp = NULL;
                // // root = root->right;
                // // while(tmp->right!=NULL)
                // //     tmp = tmp->right;
            }
        
            // return root;
        }
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        // else if(root->val > key) deleteNode(root->left, key);
        // else if(root->val < key) deleteNode(root->right, key);
        return root;
    }
    // TreeNode* findMin(TreeNode* root){
    //     if(root == NULL) return NULL;
    //     findMin(root->left);
    //     return root;
        
    // }

    
};
// @lc code=end

