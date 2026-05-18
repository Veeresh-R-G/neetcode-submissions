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
        
        if(head == nullptr){
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fur = head->next;

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* reversed_list = reverse(head);

        ListNode* prev = nullptr;
        ListNode* curr = reversed_list;
        n--;

        while(n > 0){
            prev = curr;
            curr = curr->next;
            n--;
        }

        if(prev == nullptr){
            return reverse(curr->next);
        }

        prev->next = curr->next;
        delete curr;

        ListNode* ans = reverse(reversed_list);
        return ans;

    }
};
