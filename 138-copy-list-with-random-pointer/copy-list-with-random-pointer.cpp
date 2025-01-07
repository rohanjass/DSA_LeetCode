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
            Node* copy=new Node(temp->val);
            copy->next=nextTemp;
            temp->next=copy;
            temp=nextTemp;
        }
    }
    void copyRandom(Node* head){
        Node* temp=head;
        while(temp){
            Node* copynode=temp->next;
            if(temp->random){
                copynode->random=temp->random->next;
            } else{
                copynode->random=NULL;
            }
        temp=temp->next->next;
        }
    }
    Node* seprateDeepCopy(Node* head){
        Node* temp=head;
        Node* dummy=new Node(-1);
        Node* deepCopy=dummy;
        while(temp && temp->next){
            deepCopy->next=temp->next;
            temp->next=temp->next->next;//restore back orginal LinkedList
            temp=temp->next;//moving ahead
            deepCopy=deepCopy->next;
        }
    return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertInBtw(head);
        copyRandom(head);
        return seprateDeepCopy(head);
    }
};