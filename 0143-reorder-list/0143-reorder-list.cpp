class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Step 1: Store all node pointers in a vector
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        // Step 2: Re-link nodes using two pointers
        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;
            if (i == j) break;
            nodes[j]->next = nodes[i];
            j--;
        }
        
        // Step 3: Set the last node's next to nullptr to avoid cycles
        nodes[i]->next = nullptr;
    }
};
