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
    int sum = 0;
    int l;
    int h;
    void findSum (TreeNode* root) {
        if (root == NULL) return;

        if (root->val >= l && root->val <= h) {
            sum += root->val;
        }

        findSum(root->left);
        findSum(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        findSum(root);
        return sum;
    }
};
