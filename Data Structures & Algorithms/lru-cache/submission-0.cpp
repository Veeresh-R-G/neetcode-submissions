class ListNode{
    //we need two pointers because of O(1) constraint
    // if we have SLL, then we would need to traverse the list from the front to re-arrange the pointers
    public:
        int val;
        int key;
        ListNode* next;
        ListNode* prev;
    
    ListNode(){

    }

    ListNode(int key, int val){
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class LRUCache {
public:
    int cap;
    ListNode* tail, *head;
    unordered_map<int, ListNode*> umap;
    
    LRUCache(int capacity) {
        cap = capacity;
        tail = new ListNode(0, 0);
        head = new ListNode(0, 0);
        tail->next = head;
        head->prev = tail;
    }

    void remove(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void insert(ListNode* node){
        node->prev = head->prev;
        head->prev->next = node;
        node->next = head;
        head->prev = node;
    }
    
    int get(int key) {

        if(umap.find(key) == umap.end()){
            return -1;
        }
        
        //Re Arrage to make it most recently used key

        ListNode* node = umap[key];
        remove(node);
        insert(node);
        return node->val;

    }
    
    void put(int key, int value) {    
        
        if(umap.find(key) != umap.end()){
            remove(umap[key]);
        }

        ListNode* newNode = new ListNode(key, value);
        umap[key] = newNode;
        insert(newNode);

        if(umap.size() > cap){
            ListNode* lru_node = tail->next;
            remove(lru_node);
            umap.erase(lru_node->key);
            delete lru_node;
        }

    }
};
