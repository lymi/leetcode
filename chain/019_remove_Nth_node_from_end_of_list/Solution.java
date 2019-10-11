/**
 *  Given a linked list, remove the n-th node from
 *  the end of list and return its head.
 */
class Solution {
  public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode front = head;
    while (n-- > 0) {
      front = front.next;
    }

    if (front == null) return head.next;

    ListNode behind = head;
    while (front.next != null) {
      behind = behind.next;
      front = front.next;
    }

    behind.next = behind.next.next;
    return head;
  }
}
