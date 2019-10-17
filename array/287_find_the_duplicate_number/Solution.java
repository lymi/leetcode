/**
 *
 * Given an array nums containing n + 1 integers 
 * where each integer is between 1 and n (inclusive), 
 * prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, 
 * find the duplicate one.
 * =================================================
 * 对于数组 [2,6,4,1,3,1,5]
 * index: 0 1 2 3 4 5 6
 * value: 2 6 4 1 3 1 5
 * index与value共同组成一个有环的链表:
 * 0 -> 2 -> 4 -> 3 -> 1 ->6 -> 5
 *                     |--------|
 */

class Solution {
  public int findDuplicate(int[] nums) {
    // slow 从链表的第二项开始
    int slow = nums[0], fast = nums[nums[0]];

    while(slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
}

