/**
 * Reverse a singly linked list
 */

class Solution {
  public ListNode reverseList(ListNode head) {
    ListNode newHead = new ListNode(-1);
    ListNode temp;
    while(head != null) {
      temp = newHead.next;
      newHead.next = head;
      head = head.next;
      newHead.next.next = temp;
    }
    return newHead.next;
  }
}
