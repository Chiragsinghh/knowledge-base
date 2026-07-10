/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return nullptr;
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,bool>vis;

        queue<Node*>q;
        mp[node] = new Node(node->val);
        q.push(node);


        while(!q.empty()){
            auto src = q.front();
            q.pop();
            if(vis[src]){
                continue;
            }
            vis[src]=true;

            for(auto nbr:src->neighbors){
                if(mp.find(nbr)==mp.end()){
                    mp[nbr]= new Node(nbr->val);

                }
                mp[src]->neighbors.push_back(mp[nbr]);
                if(!vis[nbr]){
                    q.push(nbr);
                }
            }

        }
        return mp[node];
    }
};