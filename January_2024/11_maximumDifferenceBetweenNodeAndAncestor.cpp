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
    int maxi = INT_MIN;
    pair<int,int> solve(TreeNode* root, int maximum, int minimum) {
        if (root == NULL) {
            return {INT_MIN,INT_MAX};
        }

        maximum = max(root->val,maximum);
        minimum = min(root->val,minimum);
        pair<int,int> left = solve(root->left,maximum, minimum);
        pair<int,int> right = solve(root->right,maximum,minimum);
        maxi = max(maxi,abs(maximum-minimum));
        return {maximum,minimum};
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,INT_MIN,INT_MAX);
        return maxi;
    }
};
