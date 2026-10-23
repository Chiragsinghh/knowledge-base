/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        int ans = 0;
        void helper(TreeNode* startNode,unordered_map<int,TreeNode*>&parent){
            unordered_map<int,bool>vis;
            vis[startNode->val]=true;
            queue<pair<TreeNode*,int>>q;

            q.push({startNode,0});

            while(!q.empty()){
                int size = q.size();

                for(int i=0;i<size;i++){
                    auto [curr,time] = q.front();
                    q.pop();
                    vis[curr->val] = true;
                    ans = max(ans,time);

                    if(curr->left && !vis[curr->left->val]){
                        q.push({curr->left,time+1});
                    }
                    if(curr->right && !vis[curr->right->val]){
                        q.push({curr->right,time+1});
                    }
                    if(parent[curr->val] && !vis[parent[curr->val]->val]){
                        q.push({parent[curr->val],time+1});
                    }
                }
            }
        }
		int amountOfTime(TreeNode* root, int start){
            if(!root) return 0;
            unordered_map<int,TreeNode*>parent;
            queue<TreeNode*>q;
            TreeNode* startNode;

            q.push(root);

            while(!q.empty()){
                auto top = q.front();
                if(top->val == start){
                    startNode = top;
                }
                q.pop();

                if(top->left){
                    q.push(top->left);
                    parent[top->left->val]=top;
                }

                if(top->right){
                    q.push(top->right);
                    parent[top->right->val]=top;
                }
            }

        helper(startNode,parent);
        return ans;


		}	
};