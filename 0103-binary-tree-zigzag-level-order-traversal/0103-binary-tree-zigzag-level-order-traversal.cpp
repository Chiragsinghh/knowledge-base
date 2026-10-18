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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        int count =0;

        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            int size = st.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                auto curr = st.front();
                st.pop();

                temp.push_back(curr->val);

                if(curr->left)st.push(curr->left);
                if(curr->right)st.push(curr->right);
            }
            if(count%2 != 0){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            count++;
                  
        }
        return ans;

    }
};