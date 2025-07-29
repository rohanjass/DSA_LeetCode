class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key,int _val){
                key=_key;
                val=_val;
                next=nullptr;
                prev=nullptr;
            }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;

    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp; 
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode; 
    }
    void delNode(Node* node){
        Node* nextN=node->next;
        Node* prevN=node->prev;
        nextN->prev=prevN;
        prevN->next=nextN;
    }


    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* keyNode=mp[key];
        int value=keyNode->val;
        mp.erase(key);
        delNode(keyNode);
        addNode(keyNode);
        mp[key]=keyNode;
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existingNode=mp[key];
            mp.erase(key);
            delNode(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */