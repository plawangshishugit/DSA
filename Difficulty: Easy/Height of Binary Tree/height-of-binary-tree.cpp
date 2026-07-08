/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int height(Node* root) {
        // Base case
        if (root == nullptr) {
            return -1;
        }

        // Height of left subtree
        int left = height(root->left);

        // Height of right subtree
        int right = height(root->right);

        // Height of current node
        return 1 + max(left, right);
    }
};