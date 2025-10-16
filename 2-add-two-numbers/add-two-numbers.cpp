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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        while(l1 || l2 ||carry){
            int dig1=(l1!=nullptr)? l1->val:0;
            int dig2=(l2!=nullptr)? l2->val:0;

            int sum=carry+dig1+dig2;
            int sumy=sum%10;
            carry=sum/10;
            
            ListNode* node=new ListNode(sumy);
            temp->next=node;
            temp=temp->next;

            l1=(l1!=nullptr)? l1->next: nullptr;
            l2=(l2!=nullptr)? l2->next: nullptr;
        }
        ListNode* res=dummy->next;
        delete dummy;
    return res;
    }
};
