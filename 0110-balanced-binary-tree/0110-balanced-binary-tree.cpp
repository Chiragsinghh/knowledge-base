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
    int getheight(TreeNode* root){
        if (root == NULL){
        return 0;
    }
    int lans = getheight(root->left) +1;
    int rans = getheight(root->right)+1;
    return max(lans,rans);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lh = getheight(root->left);
        int rh = getheight(root->right);

        int diff = abs(lh-rh);
        if(diff>1){
            return false;
        }else{
        int right = isBalanced(root->right);
        int left = isBalanced(root->left);

        if(left == true && right == true){
            return true;
        }else{
            return false;
        }
    }
    }
};