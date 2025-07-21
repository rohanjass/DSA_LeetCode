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
    ListNode* reverseList(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
    return prev;
    }
    ListNode* kthNode(ListNode* head,int k){
        k--;
        ListNode* temp=head;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
    return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* knode=kthNode(temp,k);
            if(knode==nullptr){
                if(prev!=nullptr) prev->next=temp;
                break;
            }
            ListNode* next=knode->next;
            knode->next=nullptr;
            reverseList(temp);
            if(temp==head){
               head=knode; 
            }
            else{
                prev->next=knode;
            }
            prev=temp;
            temp=next;
        }
    return head;
    }
};