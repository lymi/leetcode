/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes 
 * of the first two lists.
 */

class Solution {
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    ListNode head = new ListNode(-1);
    ListNode curr = head;

    while (l1 != null && l2 != null) {
      if (l1.val <= l2.val) {
        curr.next = l1;
        l1 = l1.next;
      } else if (l1.val > l2.val) {
        curr.next = l2;
        l2 = l2.next;
      }
      curr = curr.next;
    }

    if (l1 == null) curr.next = l2;
    if (l2 == null) curr.next = l1;
    return head.next;
  }
}

