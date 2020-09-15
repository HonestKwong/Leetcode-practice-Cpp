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
//错误，严重错误
    TreeNode* mirrorTree(TreeNode* root) {
        recur(root->left,root->right);
        return root;
    }

    void recur(TreeNode* left,TreeNode* right){
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        if(left->left==NULL && left->right!=NULL)  {
            left->left =left->right;
            left->right = NULL;
            }
        else if(left->left!=NULL && left->right==NULL){
            left->left =left->right;
            left->right = NULL;
            }
        else if(right->left==NULL && right->right!=NULL){
            right->left =right->right;
            left->right = NULL;
            }
        else if(right->left!=NULL && right->right==NULL){
            right->left =right->right;
            right->right = NULL;
            }
        else if(left->left!=NULL && left->right!=NULL&&right->right!=NULL&&right->right!=NULL){
        recur(right->left,right->right);
        recur(left->left,left->right);
        }

    }
};

//递归解法效果不佳，可以尝试使用辅助栈
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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};