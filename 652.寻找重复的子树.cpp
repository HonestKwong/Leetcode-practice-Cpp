/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode-cn.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (54.87%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 23.4K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 * 
 * 示例 1：
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * 下面是两个重复的子树：
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * 和
 * 
 * ⁠   4
 * 
 * 
 * 因此，你需要以列表的形式返回上述重复子树的根结点。
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
    vector<TreeNode*> res;
    unordered_map<string, int> subConstruction ;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recur(root);
        return res;
    }
    string recur(TreeNode* root){
        if(root == NULL) return " ";
        string leftConstruction = recur(root->left);
        string rightConstruction = recur(root->right);
        string tmp = to_string(root->val) +','+ leftConstruction + ','+ rightConstruction; //这里的逗号用来区分例如11和1，1的情况，不能少！！！
        subConstruction[tmp]++;
        if(subConstruction[tmp]==2) res.push_back(root);
        return tmp;
    }
};
// @lc code=end

