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
    bool ans =true;
    long long prev = LONG_MIN;
    vector<int>ino;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(prev>=root->val) ans = false;
        ino.push_back(root->val);
        prev = root->val;
        solve(root->right);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        solve(root);
        return ans;
    }
};