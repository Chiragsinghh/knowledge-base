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
    TreeNode* findparentandtargetnoder(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*> &parent){
        TreeNode* targetnode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->val == start){
                targetnode = front;
            }

            if(front->left){
                q.push(front->left);
                parent[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                parent[front->right] = front;
            }
        }
        return targetnode;
    }
    int burntime(TreeNode* target,unordered_map<TreeNode*,TreeNode*>& parent){
        unordered_map<TreeNode*,bool> isburnt;
        isburnt[target] = true;
        int T =0;
        queue<TreeNode*>q;
        q.push(target);
        
        while(!q.empty()){
            bool isburning = false;
            int size = q.size();
            for(int i=0;i<size;i++){
                
            auto front = q.front();
            q.pop();
            if(front->left && !isburnt[front->left]){
                q.push(front->left);
                isburnt[front->left]= true;
                isburning = true;
            }
            if(front->right && !isburnt[front->right]){
                q.push(front->right);
                isburnt[front->right]= true;
                isburning = true;
            }
            if(parent[front] && !isburnt[parent[front]]){
                q.push(parent[front]);
                isburnt[parent[front]]= true;
                isburning = true;
            }
            
            }
            if(isburning){
                T++;
            }
            
        }
        return T;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* target = findparentandtargetnoder(root,start,parent);
        return burntime(target,parent);
        
    }
};