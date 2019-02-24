/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    void connect(Node* l, Node *r) {
        if (r == nullptr) {
            return;
        }
        l->next = r;
        connect(l->left, l->right);
        connect(l->right, r->left);
        connect(r->left, r->right);
    }
    Node* connect(Node* root) {
        if (root != nullptr) {
            connect(root->left, root->right);
        }
        return root;
    }
};
