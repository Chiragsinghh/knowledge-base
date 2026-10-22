#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root) return ans;

        // Step 1: Map each node to its parent
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top->left) {
                q.push(top->left);
                parent[top->left->val] = top;
            }
            if (top->right) {
                q.push(top->right);
                parent[top->right->val] = top;
            }
        }

        // Step 2: BFS from target node outward (left, right, parent) up to distance k
        unordered_map<int, bool> vis;
        q.push(target);
        vis[target->val] = true;
        int currentLevel = 0;

        while (!q.empty()) {
            if (currentLevel == k) break;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();

                // Left child
                if (top->left && !vis[top->left->val]) {
                    vis[top->left->val] = true;
                    q.push(top->left);
                }
                // Right child
                if (top->right && !vis[top->right->val]) {
                    vis[top->right->val] = true;
                    q.push(top->right);
                }
                // Parent node
                if (parent.find(top->val) != parent.end() && !vis[parent[top->val]->val]) {
                    vis[parent[top->val]->val] = true;
                    q.push(parent[top->val]);
                }
            }
            currentLevel++;
        }

        // Step 3: Collect all nodes left in the queue at distance k
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
