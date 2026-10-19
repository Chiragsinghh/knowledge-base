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
    void solve(TreeNode* root,int x,int y,map<int, map<int, multiset<int>>>& mp){
        if(!root) return;

        mp[y][x].insert(root->val);
        solve(root->left,x+1,y-1,mp);
        solve(root->right,x+1,y+1,mp);


    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, map<int, multiset<int>>> mp;

        solve(root,0,0,mp);

        for(auto& [col,rowmap]:mp){
            vector<int>colValues;
            for(auto& [row,values]:rowmap){
                colValues.insert(colValues.end(), values.begin(), values.end());
            }
            ans.push_back(colValues);
        }

        return ans;


    }
};