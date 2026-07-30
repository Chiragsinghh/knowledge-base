class Solution {
public:
    bool solve(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;
        
        return solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true;
        
        if (root->val == subRoot->val && solve(root, subRoot)) {
            return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
