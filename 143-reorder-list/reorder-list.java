/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head){
        ListNode prev=null;
        ListNode temp=head;
        while(temp!=null){
            ListNode tempNext=temp.next;
            temp.next=prev;
            prev=temp;
            temp=tempNext;
        }
    return prev;
    }

    public void reorderList(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode secondRevHalf=reverseList(slow.next);
        slow.next=null;
        ListNode first=head;
        
        while(secondRevHalf!=null){
            ListNode temp1=secondRevHalf.next;
            ListNode temp2=first.next;
            first.next=secondRevHalf;
            secondRevHalf.next=temp2;
            first=temp2;
            secondRevHalf=temp1;
        }
    }
}