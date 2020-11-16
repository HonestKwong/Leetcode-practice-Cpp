/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (68.49%)
 * Likes:    752
 * Dislikes: 0
 * Total Accepted:    128.2K
 * Total Submissions: 187.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurTree(preorder, inorder, 0, preorder.size()-1, inorder.begin(), inorder.end());
    }

    TreeNode* recurTree(vector<int>& preorder, vector<int>& inorder, int p, int q, vector<int>::iterator m, vector<int>::iterator n){
        if(p-q>0) return NULL;   //二叉树的这个判断条件比较重要
        TreeNode* root = new TreeNode(preorder[p]);
        auto it = find(m, n, preorder[p]);
        int mid = it - m;
        root->left = recurTree(preorder, inorder, p+1, p+mid, m, it);
        root->right = recurTree(preorder, inorder,p+1+mid, q, it+1, n);
        return root;
    }
};
// @lc code=end

