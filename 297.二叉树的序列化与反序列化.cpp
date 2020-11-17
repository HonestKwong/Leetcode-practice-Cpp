/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "n";
        string res;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()!=0){
            int n = que.size();
            for(int i = 0; i<n; i++){
                TreeNode* tmp = que.front();
                if(tmp!=NULL){
                    // res += to_string(que.front()->val) + ",";
                    res.append(to_string(que.front()->val));
                    res.append(",");
                    que.push(tmp->left);
                    que.push(tmp->right);
                    }
                else {
                
                    res.append("n,");
                }
                que.pop();
            }
        }
        res.pop_back();
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "n") return NULL;
        vector<string> tmp = splitStr(data);
        int node = 0;
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoi(tmp[node++]));
        que.push(root);
        int n = que.size();
        while(!que.empty()){
            for(int i = 0; i<n; i++){
                auto left = tmp[node++];
                auto right = tmp[node++];
                if(left != "n") {
                    que.front()->left = new TreeNode(stoi(left));
                    que.push(que.front()->left);
                    }
                if(right != "n"){
                    que.front()->right = new TreeNode(stoi(right));
                    que.push(que.front()->right);
                }
                que.pop();
            }
            n = que.size();
        }
        return root;

    }
    vector<string> splitStr(const string &data){
        vector<string> res;
        char *datas = new char[data.size()+1];
        strcpy(datas, data.c_str());
        char* p = strtok(datas, ",");
        while(p){
            string s = p;
            res.push_back(s);
            p = strtok(NULL, ",");
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

