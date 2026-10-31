struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }  
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            if(!head){
                head = front;
                tail = front;
            }else{
                tail->next = front;
                tail = tail->next;
            }

            if(front->next){
                pq.push(front->next);
            }
        }

        return head;
    }
};