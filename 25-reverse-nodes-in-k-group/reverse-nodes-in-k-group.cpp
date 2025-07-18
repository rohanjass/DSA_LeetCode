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
    ListNode* kthNode(ListNode* node,int k){
        k-=1;
        ListNode* temp=node;
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
            ListNode* kthNodeE=kthNode(temp,k);
            if(kthNodeE==nullptr){
                if(prev!=nullptr) prev->next=temp;
                break;
            }
            ListNode* nextToKthNode=kthNodeE->next;
            kthNodeE->next=nullptr;
            reverseList(temp);
            if(temp==head){
                head=kthNodeE;
            } else {
                prev->next=kthNodeE; 
            }
            prev=temp;
            temp=nextToKthNode;
        }
    return head;
    }
};