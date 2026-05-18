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

    ListNode* reverse(ListNode* head){

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* upcom = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = upcom;
            if(upcom){
                upcom = upcom->next;
            }
        }

        return prev;
    }

    void print(ListNode* head){

        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void reorderList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // one node case, prev will still be nullptr
        if(prev == nullptr){
            return;
        }

        prev->next = nullptr;

        ListNode* reversed_list = reverse(slow);

        ListNode* temp_rev = reversed_list;
        ListNode* temp_head = head;
        ListNode* temp_rev_prev = nullptr;

        while(temp_rev && temp_head){
            
            ListNode* temp_head_next = temp_head->next;
            ListNode* temp_rev_next = temp_rev->next;

            temp_head->next = temp_rev;

            temp_rev->next = temp_head_next;

            temp_head = temp_head_next;
            temp_rev_prev = temp_rev;
            temp_rev = temp_rev_next;

        }

        if(temp_rev){
            temp_rev_prev->next = new ListNode(temp_rev->val);
        }

    
    }
};
