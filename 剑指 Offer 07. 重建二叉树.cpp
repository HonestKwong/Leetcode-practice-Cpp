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
    TreeNode* recusionbuild(vector<int>::iterator preBegin,vector<int>::iterator preEnd,vector<int>::iterator inBegin,vector<int>::iterator inEnd){
        if(inBegin==inEnd) return NULL;
        TreeNode* cur = new TreeNode(*preBegin); //C++的构造函数
        // vector<int>::iterator root = find(inBegin, inEnd, *preBegin);
        auto root = find(inBegin, inEnd, *preBegin);
        cur->left = recusionbuild(preBegin+1,preBegin+1+(root-inBegin),inBegin,root);
        cur->right = recusionbuild(preBegin+1+(root-inBegin),preEnd, root+1,inEnd);
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recusionbuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
};