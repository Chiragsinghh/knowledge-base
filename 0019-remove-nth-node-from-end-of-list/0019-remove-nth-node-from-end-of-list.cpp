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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        long long length =1;

        ListNode* ptr = head;
        while(ptr->next){
            ptr=ptr->next;
            length++;
        }

        if (length == n) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        
        ListNode* curr = head;
        ListNode*prev=nullptr;

        int i=0;

        while(i<length-n){
            prev=curr;
            curr=curr->next;
            i++;
            
        }
        prev->next=curr->next;
        delete curr;

        return head;

    }
};