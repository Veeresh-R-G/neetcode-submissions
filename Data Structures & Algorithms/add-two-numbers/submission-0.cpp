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
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fur = curr->next;

        while(curr){
            
            curr->next = prev;
            prev = curr;
            curr = fur;
            if(fur){
                fur = fur->next;
            }
        }

        return prev;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode();
        ListNode* temp_ans = ans;

        int carry = 0;

        while(temp1 && temp2){

            int sum = carry + temp1->val + temp2->val;
            carry = sum / 10;

            temp_ans->next = new ListNode(sum % 10);

            temp1 = temp1->next;
            temp2 = temp2->next; 
            temp_ans = temp_ans->next;

        }

        while(temp1){
            int sum = carry + temp1->val;
            carry = sum / 10;

            temp_ans->next = new ListNode(sum % 10);

            temp1 = temp1->next;
            temp_ans = temp_ans->next;
        }

        while(temp2){
            int sum = carry + temp2->val;
            carry = sum / 10;

            temp_ans->next = new ListNode(sum % 10);

            temp2 = temp2->next;
            temp_ans = temp_ans->next;
        }

        if(carry){
            temp_ans->next = new ListNode(carry);
        }

        return ans->next;
    }
};
