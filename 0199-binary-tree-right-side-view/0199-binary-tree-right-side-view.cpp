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
    void helper(TreeNode* root,vector<int>&ans,int hl){
        if(!root) return;

        if(hl == ans.size()){
            ans.push_back(root->val);
        }
        helper(root->right,ans,hl+1);
        helper(root->left,ans,hl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;

        helper(root,ans,0);
        return ans;
    }
};