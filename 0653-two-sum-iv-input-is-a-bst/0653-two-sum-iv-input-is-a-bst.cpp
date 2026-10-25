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
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ino;
        inorder(root,ino);

        bool ans = false;

        int s = 0;
        int e = ino.size()-1;

        while(s<e){
            if(ino[s]+ino[e]==k){
                return true;
            }

            if(ino[s]+ino[e]<k){
                s++;
            }

            if(ino[s]+ino[e]>k){
                e--;
            }
        }

        return ans;
    }
};