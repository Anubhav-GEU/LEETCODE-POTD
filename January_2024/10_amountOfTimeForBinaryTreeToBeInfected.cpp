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
    int timeToInfect = 0;
    unordered_map<TreeNode*,TreeNode*> mp;
    TreeNode* first = NULL;
    void findParent(TreeNode* root) {
        if (root == NULL) return;

        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;
        findParent(root->left);
        findParent(root->right);
    }
    void findNode(TreeNode* root, int start) {
        if (root == NULL) return;

        if (root->val == start) first = root;

        findNode(root->left,start);
        findNode(root->right,start);
    }
    void findTime() {
        queue<pair<TreeNode*,int>> q;
        q.push({first,0});
        unordered_set<TreeNode*> st;
        st.insert(first);
        while (q.empty() == false){
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                TreeNode* curr = node.first;
                int time = node.second;

                if (curr->left && st.find(curr->left) == st.end()) {
                    q.push({curr->left,time+1});
                    st.insert(curr->left);
                }
                if (curr->right && st.find(curr->right) == st.end()) {
                    q.push({curr->right,time+1});
                    st.insert(curr->right);
                }
                if (mp[curr] != NULL && st.find(mp[curr]) == st.end()){
                    q.push({mp[curr],time+1});
                    st.insert(mp[curr]);
                } 
                if (q.empty() == true) {
                    timeToInfect = time;
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        findParent(root);
        findNode(root,start);
        findTime();
        return timeToInfect;
    }
};
