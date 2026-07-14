/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct compare{
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto node:lists){
            if(node!=NULL){
                pq.push(node);
            }
            
        }

        ListNode* head= NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            if(head==NULL && tail==NULL){
                head=front;
                tail=front;
            }else{
                tail->next=front;
                tail=front;
            }
            if(front->next!=NULL){
                pq.push(front->next);
            }
            

        }
        return head;



    }
};