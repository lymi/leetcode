/**
 * Median of Two Sorted Arrays
 */

class Solution {
  public ListNode swapPairs(ListNode head) {
    ListNode newHead = new ListNode(-1);
    newHead.next = head;

    ListNode prev = newHead;
    ListNode temp = null;

    while (prev.next != null && prev.next.next != null) {
      temp = prev.next.next;
      prev.next.next = temp.next;
      temp.next = prev.next;
      prev.next = temp;
      prev = prev.next.next;
    }
    return newHead.next;
  }
}

