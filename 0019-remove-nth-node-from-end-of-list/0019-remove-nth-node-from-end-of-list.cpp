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
        if(!head){
            return NULL;
        }
        int total =0;

        ListNode*ptr = head;

        while(ptr){
            total++;
            ptr=ptr->next;
        }

        int goal = total-n;
        if(goal==0){
            head=head->next;
        }

        ptr = head;

        while(goal>0){
            if(goal==1){
                ptr->next=ptr->next->next;
            }
            ptr=ptr->next;
            goal--;
        }
        

        return head;
        
    }
};