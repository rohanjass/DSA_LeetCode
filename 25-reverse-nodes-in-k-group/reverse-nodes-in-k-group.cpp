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
    ListNode* revList(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* tempNext=temp->next;
            temp->next=prev;
            prev=temp;
            temp=tempNext;
        }
    return prev;
    }
    ListNode* kThNode(ListNode* head,int k){
        k--;
        ListNode* temp=head;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
    return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* kth_node=kThNode(temp,k);
            if(kth_node==nullptr){
                if(prev!=nullptr){
                    prev->next=temp;
                }
                break;
            }

            ListNode* next=kth_node->next;
            kth_node->next=nullptr;

            revList(temp);

            if(temp==head){
                head=kth_node;
            } else {
                prev->next=kth_node;
            }
            prev=temp;
            temp=next;
        }
    return head;
    }
};