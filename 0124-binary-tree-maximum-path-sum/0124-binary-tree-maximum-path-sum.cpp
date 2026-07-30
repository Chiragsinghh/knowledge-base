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
    int maxsum =INT_MIN;

    int maxpathsum(TreeNode* root){
        if(!root) return 0;

        int leftsum = max(0,maxpathsum(root->left));
        int rightsum = max(0,maxpathsum(root->right));

        int currsum = root->val + leftsum +rightsum;

        maxsum = max(maxsum, currsum);

        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxpathsum(root);
        return maxsum;

    
    }
};