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

    ListNode* reverseLL(ListNode* head){
        if(head and head->next == nullptr){
            return head;
        }

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    void reorderList(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* r_head = reverseLL(slow->next);
        slow->next = nullptr;
        ListNode* f_head = head;
        ListNode* r_next = nullptr, *f_next = nullptr;
        while(r_head and f_head){
            f_next = f_head->next;
            r_next = r_head->next;
            f_head->next = r_head;
            r_head->next = f_next;
            r_head = r_next;
            f_head = f_next; 
        }

        

    }
};
