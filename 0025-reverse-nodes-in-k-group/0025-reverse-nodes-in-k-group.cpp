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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr= head;
        int count=0;
        while(ptr!=NULL && count<k){
            ptr=ptr->next;
            count++;
        }

        if(count==k){
            ListNode* prev=NULL;
            ListNode* forward=NULL;
            ListNode* curr = head;

            int i=0;
            while(i<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                i++;
            }

            ListNode* recans=reverseKGroup(forward,k);
            head->next=recans;
            return prev;


        }
        else{
            return head;

        }
    }
};