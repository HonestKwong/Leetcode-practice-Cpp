/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (44.82%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    148.4K
 * Total Submissions: 330.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
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
    int minDepth(TreeNode* root) {
        //这个就是层序遍历吧？
        if(root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        while(!que.empty()){
            int sz = que.size();
            for(int i=0;i<sz;i++){  //这里的sz不能替换
                if(que.front()->left == NULL && que.front()->right == NULL) return depth;
                if(que.front()->left != NULL) que.push(que.front()->left);
                if(que.front()->right != NULL) que.push(que.front()->right);
                que.pop();                
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

