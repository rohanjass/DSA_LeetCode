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
    void insertInBtw(Node* head){
        Node* temp=head;
        while(temp){
            Node* nextTemp=temp->next;
            Node* copyNode=new Node(temp->val);
            temp->next=copyNode;
            copyNode->next=nextTemp;
            temp=nextTemp;
        }
    }
    void copyRandom(Node* head){
        Node* temp=head;
        while(temp){
            Node* copyNode=temp->next;
            if(temp->random){
                copyNode->random=temp->random->next;
            } else {
                copyNode->random=nullptr;
            }
        temp=temp->next->next;
        }
    }

    Node* seprateList(Node* head){
        Node* temp=head;
        Node* dummy=new Node(-1);
        Node* deepCopy=dummy;
        while(temp && temp->next){
            deepCopy->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            deepCopy=deepCopy->next;
        }
    return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        insertInBtw(head);
        copyRandom(head);
        return seprateList(head);
    }
};