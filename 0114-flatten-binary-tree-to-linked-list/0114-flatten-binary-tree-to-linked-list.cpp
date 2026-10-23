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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        // Flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);
        
        // Store the right subtree
        TreeNode* tempRight = root->right;
        
        // Move left subtree to the right
        root->right = root->left;
        root->left = nullptr;
        
        // Traverse to the end of the new right subtree
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }
        
        // Attach the original right subtree
        curr->right = tempRight;
    }
};