/**
 * Write a program to find the node at which 
 * the intersection of two singly linked lists begins.
 */

public class Solution {
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    ListNode p1 = headA, p2 = headB;
    while(p1 != p2) {   // 如果不存在交点，p1与p2将同时为null
      p1 = (p1 == null) ? headB : p1.next;
      p2 = (p2 == null) ? headA : p2.next;
    }
    return p1;
  }
}

