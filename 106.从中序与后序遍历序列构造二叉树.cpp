/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (70.72%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    76.8K
 * Total Submissions: 108.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     return recurTree(postorder, inorder, 0, postorder.size()-1, inorder.begin(), inorder.end());   
    }

    TreeNode* recurTree(vector<int>& postorder, vector<int>& inorder, int p, int q, vector<int>::iterator m, vector<int>::iterator n){
        if(p-q>0) return NULL;
        TreeNode* root = new TreeNode(postorder[q]);
        auto it = find(m, n, postorder[q]);
        int mid = it - m;
        root->right = recurTree(postorder, inorder, p+mid, q-1,it+1, n);
        root->left = recurTree(postorder, inorder, p, p+mid-1,  m, it);
        return root;
    }
};

// @lc code=end

