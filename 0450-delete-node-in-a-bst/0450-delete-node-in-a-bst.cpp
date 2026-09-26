/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getmax(TreeNode* root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }

        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            if (!root->left && root->right) {
                TreeNode* Temp = root->right;
                delete root;
                return Temp;
            }

            if (root->left && !root->right) {
                TreeNode* Temp = root->left;
                delete root;
                return Temp;
            }

            if (root->left && root->right) {
                int max = getmax(root);
                root->val = max;
                root->left = deleteNode(root->left, max);
                return root;
            }
        } else {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};