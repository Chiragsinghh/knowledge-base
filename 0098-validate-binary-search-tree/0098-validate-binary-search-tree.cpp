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
    bool ans = true;
    long long prev = LONG_MIN;
    void inorder(TreeNode* root,vector<int> &ino){
        if(!root) return;
        inorder(root->left,ino);
        if(prev >= root->val) ans = false;
        ino.push_back(root->val);
        prev = root->val;
        inorder(root->right,ino);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ino;
        inorder(root,ino);
        return ans;
    }
};