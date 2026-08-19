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
        int count =0;
        ListNode* ptr = head;
        while(ptr && count<k){
            ptr=ptr->next;
            count++;
        }

        if(count ==k){
            int i=0;
        ListNode* forward = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(i<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            i++;
        }

        ListNode* rechead = reverseKGroup(forward,k);
        head->next = rechead;
        return prev;
        }else{
            return head;
        }

        

    }
};