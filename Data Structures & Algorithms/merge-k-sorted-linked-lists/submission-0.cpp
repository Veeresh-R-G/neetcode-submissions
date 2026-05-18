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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return nullptr;
        }


        ListNode* ans = new ListNode(-1e5);

        for(int i = 0; i < lists.size(); i++){
            if(i == 0){
                ans = lists[0];
            } else{

                ListNode *newList = new ListNode();
                ListNode *temp_new = newList;

                ListNode* temp = ans;
                ListNode* curr_list = lists[i];

                while(temp && curr_list){
                    if(curr_list->val < temp->val){
                        temp_new->next = new ListNode(curr_list->val);
                        curr_list = curr_list->next;
                    } else{ 
                        temp_new->next = new ListNode(temp->val);
                        temp = temp->next;
                    }
                    temp_new = temp_new->next;
                }

                while(temp){
                    temp_new->next = new ListNode(temp->val);
                    temp = temp->next;
                    temp_new = temp_new->next;
                }

                while(curr_list){
                    temp_new->next = new ListNode(curr_list->val);
                    temp_new = temp_new->next;
                    curr_list = curr_list->next;
                }

                ans = newList->next;
            }
        }

        return ans->val == -1e5 ? nullptr: ans;
        
    }
};
