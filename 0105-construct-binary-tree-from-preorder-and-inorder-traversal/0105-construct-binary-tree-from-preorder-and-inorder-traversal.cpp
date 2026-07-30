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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int inorderstart,int inorderend,int & preorderidx,unordered_map<int,int>&mp){
        if(preorderidx > preorder.size()-1){
            return NULL;
        }
        if(inorderstart>inorderend){
            return NULL;
        }

        int element = preorder[preorderidx];
        preorderidx++;
        TreeNode* root = new TreeNode(element);


        int indexininorder = mp[element];
        root->left = solve(inorder,preorder,inorderstart,indexininorder-1,preorderidx,mp);
        root->right= solve(inorder,preorder,indexininorder+1,inorderend,preorderidx,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;

        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }

        int inorderstart = 0;
        int preorderidx =0;
        int inorderend = inorder.size()-1;

        TreeNode* root = solve(inorder,preorder,inorderstart,inorderend,preorderidx,mp);
        return root;



    }
};