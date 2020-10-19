class Solution {
public:
    int recur(TreeNode* root, int i){
        if (root == NULL) return i;
        i++;
        // int m = 0;
        // int n = 0;
        // m = recur(root->left, i);
        // n = recur(root->right, i);
        return max(recur(root->left, i),recur(root->right, i));

    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return recur(root, 0);
    }
};
