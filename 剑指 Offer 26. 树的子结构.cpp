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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A!=NULL&&B!=NULL)&&(recur(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B));

    }

    bool recur(TreeNode* A, TreeNode* B)
    {
        if(B==NULL) return true; //代表子树搜索到了最后一个节点
        else if(A==NULL||A->val!=B->val) return false;
        else return recur(A->left,B->left)&&recur(A->right,B->right);

    }
};