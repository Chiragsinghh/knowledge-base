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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int len =1;

        ListNode* ptr = head;
        while(ptr->next){
            len++;
            ptr=ptr->next;
        }

        int ak = k%len;

        if(ak==0) return head;

        ptr->next=head;
        ptr=head;

        for(int i=0;i<len - ak - 1;i++){
            ptr=ptr->next;
        }
        ListNode* newhead = ptr->next;
        ptr->next = nullptr;
        return newhead;
        

    }
};