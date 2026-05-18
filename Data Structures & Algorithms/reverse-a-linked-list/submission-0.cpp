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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr){
            return head;
        }

        if(head->next == nullptr){
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* fur = nullptr;

        /*
            Ques
            null <- 0 <- 1 <- 2 <- 3
                                    prev curr fur 

            0 <- 1 - 2 -> 3

            Res
            3 -> 2 -> 1 -> 0

        */
        curr = head;
        fur = curr->next;

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
};
