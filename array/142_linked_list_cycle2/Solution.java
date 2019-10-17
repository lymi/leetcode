/**
 * Given a linked list, return the node where the cycle
 * begins. If there is no cycle, return null.
 * To represent a cycle in the given linked list, we use
 * an integer pos which represents the position (0-indexed)
 * in the linked list where tail connects to. If pos is -1,
 * then there is no cycle in the linked list.
 */

public class Solution {
  public ListNode detectCycle(ListNode head) {
    if (head == null || head.next == null) return null;
    //  slow 从链表的第2个节点开始
    ListNode slow = head.next, fast = head.next.next;

    while (fast != null && fast.next != null && slow != fast) {
      slow = slow.next;
      fast = fast.next.next;
    }

    if (fast == null || fast.next == null) return null;

    fast = head;

    while (slow != fast) {
      slow = slow.next;
      fast = fast.next;
    }

    return slow;
  }
}

