/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxSum = 0;

    vector<int> solve(TreeNode* root){

        if(root == NULL){
            return {INT_MAX, INT_MIN, 0}; 
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(root->val > left[1] && root->val < right[0]){

            int sum = left[2] + right[2] + root->val;

            maxSum = max(maxSum, sum);

            int minVal = min(root->val, left[0]);
            int maxVal = max(root->val, right[1]);

            return {minVal, maxVal, sum};
        }

        return {INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {

        solve(root);
        return maxSum;
    }
};