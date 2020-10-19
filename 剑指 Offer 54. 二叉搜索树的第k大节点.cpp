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
    void recur(TreeNode* root, vector<int>& midOrder){
        if(root == NULL) return;
        recur(root->left,midOrder);
        midOrder.push_back(root->val);
        recur(root->right,midOrder);
    }
    int kthLargest(TreeNode* root, int k) {
        vector<int> midOrder;
        recur(root,midOrder);
        return midOrder[midOrder.size()-k];
    }
};