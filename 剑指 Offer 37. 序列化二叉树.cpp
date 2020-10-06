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
    string res;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        // res += string(root);
        recur(root);
        return res;
        // recur(root->right);
    }
    void recur(TreeNode* root){
        if(root == NULL){
            res+=string("NULL,");
            return;
        } 
        else{
            res += to_string(root->val)+",";
            recur(root->left);
            recur(root->right);
        }

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string data_tmp[] = data.split(",");
        queue<string> data_queue;
        // for(int i=0; i<data_tmp.size(); i++){
        //     data_queue.pop(data_tmp[i]);
        // }
        size_t pos = data.find(",");
        while(pos!=data.npos){
            string temp = data.substr(0,pos);
            data_queue.push(temp);
            data = data.substr(pos+1,data.size());
            pos = data.find(",");
        }
        
        return derecur(data_queue);
    }

    TreeNode* derecur(queue<string> data_queue){   //这里少了引用
        if(data_queue.front()=="NULL") {
            data_queue.pop();
            return NULL;
        }
        string x = data_queue.front();
        TreeNode* root = new TreeNode(std::stoi(x));
        data_queue.pop();
        root->left = derecur(data_queue);
        root->right = derecur(data_queue);
        return root;

    }
    
};

//下面这种方法会内存超出限制·····
class Codec {
public:
    string res;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        recur(root);    
        return res;
    }
    void recur(TreeNode* root){
        if(root == NULL){
            res.append("null,");   //用NULL太傻了！！！得多消耗四倍的内存！
            
        } 
        else{
            res.append(to_string(root->val));
            res.push_back(',');
            recur(root->left);
            recur(root->right);
        }
        // return res;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string data_tmp[] = data.split(",");
        // data = data+",";
        queue<string> data_queue;
        size_t pos = data.find(",");
        while(pos!=data.npos){
            string temp = data.substr(0,pos);
            data_queue.push(temp);
            data = data.substr(pos+1,data.size());
            pos = data.find(",");
        }
        // string pattern = ",";
        // char * strc = new char[strlen(data.c_str())+1];
        // strcpy(strc, data.c_str());   //string转换成C-string
        // vector<string> res;
        // char* temp = strtok(strc, pattern.c_str());
        // while(temp != NULL){
        //     data_queue.push(string(temp));
        //     temp = strtok(NULL, pattern.c_str());
        // }
        // delete[] strc;
        return derecur(data_queue);
    }

    TreeNode* derecur(queue<string>& data_queue1){
        if(data_queue1.front()=="null") {
            data_queue1.pop();
            return NULL;
        }
        string x = data_queue1.front();
        TreeNode* root = new TreeNode(std::stoi(x));
        data_queue1.pop();
        root->left = derecur(data_queue1);
        root->right = derecur(data_queue1);
        return root;

    }
    
};

class Codec {
public:
    string res;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        recur(root);    
        return res;
    }
    void recur(TreeNode* root){
        if(root == NULL){
            res.push_back('n');
            res.push_back(',');
            
            
        } 
        else{
            res.append(to_string(root->val));
            res.push_back(',');
            recur(root->left);
            recur(root->right);
        }
        // return res;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string data_tmp[] = data.split(",");
        // data = data+",";
        queue<string> data_queue;
        size_t pos = data.find(',');
        while(pos!=data.npos){
            string temp = data.substr(0,pos);
            data_queue.push(temp);
            data = data.substr(pos+1,data.size());
            pos = data.find(',');
        }
        // string pattern = ",";
        // char * strc = new char[strlen(data.c_str())+1];
        // strcpy(strc, data.c_str());   //string转换成C-string
        // vector<string> res;
        // char* temp = strtok(strc, pattern.c_str());
        // while(temp != NULL){
        //     data_queue.push(string(temp));
        //     temp = strtok(NULL, pattern.c_str());
        // }
        // delete[] strc;
        return derecur(data_queue);
    }

    TreeNode* derecur(queue<string>& data_queue1){
        if(data_queue1.front()=="n") {
            data_queue1.pop();
            return NULL;
        }
        string x = data_queue1.front();
        TreeNode* root = new TreeNode(std::stoi(x));
        data_queue1.pop();
        root->left = derecur(data_queue1);
        root->right = derecur(data_queue1);
        return root;
    }
    
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));