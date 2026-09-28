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
    bool check(TreeNode* r,TreeNode* l){
        if(r==nullptr && l==nullptr){
            return true;
        }

        if(r==nullptr || l==nullptr){
            return false;
        }

        if(r->val!=l->val){
            return false;
        }

        return check(r->left, l->right) && check(r->right, l->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root->right,root->left);
    }
};