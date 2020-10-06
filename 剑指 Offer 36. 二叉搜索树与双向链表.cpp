/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
//我的错误思路：这种链表的建立····head到底存不存在真是有点迷
    Node * pre;
    Node* cur;
    Node * head = new Node(0);
    Node* treeToDoublyList(Node* root) {
        recur(root);
        cur->right = head->right;
        head->right->left = cur;
        return head;
    }

    void recur(Node* root){
        if(root == NULL) return;
        recur(root->left);
        //打印根节点   
        cur = root;
        if(head->right == NULL) head->right = cur;
        if(pre!=NULL)pre->right = cur;
        cur->left =  pre;
        pre = cur;
        recur(root->right);
    }
};


class Solution {
public:
//正确答案
    Node * pre;
    Node* cur;
    Node * head;
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        recur(root);
        cur->right = head;
        head->left = pre;
        return head;
    }

    void recur(Node* root){
        if(root == NULL) return;
        recur(root->left);
        //打印根节点   
        cur = root;
         if(head == NULL) head = cur;
        if(pre!=NULL)pre->right = cur;
        cur->left =  pre;
        pre = cur;
        recur(root->right);
    }
};