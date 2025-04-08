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
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* nextTemp=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextTemp;
        }
    return prev;
    }
    int addList(ListNode* l1,ListNode* l2){
        int maxSum=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=nullptr && temp2!=nullptr){
            int sum=temp1->val+temp2->val;
            maxSum=max(maxSum,sum);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    return maxSum;
    }
    int pairSum(ListNode* head) {
        if(head->next->next==nullptr) return head->val+head->next->val;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp2=revList(slow);
        int maxSum=addList(head,temp2);
        return maxSum;
    }
};