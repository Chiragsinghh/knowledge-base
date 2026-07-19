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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while(ptr1 && ptr2){
            if(ptr1->val <ptr2->val){
                ptr->next = new ListNode(ptr1->val);
                ptr=ptr->next;
                ptr1=ptr1->next;
            }else{
                ptr->next = new ListNode(ptr2->val);
                ptr=ptr->next;
                ptr2=ptr2->next;
            }
        }

        if(ptr1){
            while(ptr1){
                ptr->next = new ListNode(ptr1->val);
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
        }else{
            while(ptr2){
                ptr->next = new ListNode(ptr2->val);
                ptr=ptr->next;
                ptr2=ptr2->next;
            }
            
        }
        
        return head->next;


    }
};