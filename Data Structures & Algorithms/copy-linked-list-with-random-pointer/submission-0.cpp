/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }

        unordered_map<Node*, Node*> random_ptr_map;
        random_ptr_map[nullptr] = nullptr;

        Node* temp_head = head;
        while(temp_head){
            random_ptr_map[temp_head] = new Node(temp_head->val);
            temp_head = temp_head->next;
        }

        temp_head = head;
        while(temp_head){
            random_ptr_map[temp_head]->next = random_ptr_map[temp_head->next];
            random_ptr_map[temp_head]->random = random_ptr_map[temp_head->random];
            temp_head = temp_head->next;
        }
       
        return random_ptr_map[head];

    }
};
