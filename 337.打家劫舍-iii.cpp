/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*, int> visited;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(visited.count(root)) return visited[root];
        int do_rob, not_rob;
        do_rob = root->val
            + (root->left==NULL ? 0 : rob(root->left->left) + rob(root->left->right))
            + (root->right==NULL ? 0 : rob(root->right->left) + rob(root->right->right));
        not_rob = rob(root->left) + rob(root->right);
        int res = max(do_rob,not_rob);
        visited[root] = res;
        return res;
    }
};
// @lc code=end

