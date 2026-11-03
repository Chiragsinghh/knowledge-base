class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == nullptr) {
                
                seenNull = true;
            } else {
                
                if (seenNull) return false;
                
               
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true;
    }
};
