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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return null;
        ListNode prevNode=head;
        ListNode temp=head.next;
        while(temp!=null){
            if(temp.val==prevNode.val ){
                temp=temp.next;
            }
            else{
                prevNode.next=temp;
                prevNode=temp;
                temp=temp.next;
            }
        }
        prevNode.next=null;

    return head;
    }
}