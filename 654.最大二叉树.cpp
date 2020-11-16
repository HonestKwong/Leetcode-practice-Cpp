/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 *
 * https://leetcode-cn.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (81.62%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 30.2K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
 * 
 * 
 * 二叉树的根是数组中的最大元素。
 * 左子树是通过数组中最大值左边部分构造出的最大二叉树。
 * 右子树是通过数组中最大值右边部分构造出的最大二叉树。
 * 
 * 
 * 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
 * 
 * 
 * 
 * 示例 ：
 * 
 * 输入：[3,2,1,6,0,5]
 * 输出：返回下面这棵树的根节点：
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的数组的大小在 [1, 1000] 之间。
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
class Solution1 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* res = recurTree(nums, 0, nums.size());
        return res;

    }

    TreeNode* recurTree(const vector<int>& nums, int start, int end){
        if(start - end >=0) return NULL;
        auto it = max_element(nums.begin()+start, nums.begin()+end);
        TreeNode* root = new TreeNode(*it);
        root->left = recurTree(nums, start, it-nums.begin());  //这样写迭代器容易想不清楚
        root->right = recurTree(nums, it-nums.begin()+1, end);
        return root;
    }
};


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* res = recurTree(nums, nums.begin(), nums.end());
        return res;

    }

    TreeNode* recurTree(const vector<int>& nums, vector<int>::iterator start, vector<int>::iterator end){
        if(start-end>=0) return NULL;
        vector<int>::iterator it = max_element(start, end);
        TreeNode* root = new TreeNode(*it);
        root->left = recurTree(nums, start, it);
        root->right = recurTree(nums, it+1, end);
        return root;
    }
};
// @lc code=end

