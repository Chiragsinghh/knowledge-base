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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            auto left = q.front().second;
            auto right = q.back().second;
            maxWidth = max(maxWidth,(int)(right-left+1));

            for (int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                auto current = front.first;
                auto idx = front.second;
                
                if(current->left) q.push({current->left,idx*2});
                if(current->right) q.push({current->right,2*idx+1});
            }
        }
        return maxWidth;
    }
};