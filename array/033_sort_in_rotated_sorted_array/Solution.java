/**
 *
 * Suppose an array sorted in ascending order is rotated at
 * some pivot unknown to you beforehand. (i.e., [0,1,2,4,5,6,7]
 * might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array
 * return its index, otherwise return -1. You may assume no
 * duplicate exists in the array.Your algorithm's runtime complexity
 * must be in the order of O(log n).
 */

class Solution {
  public int search(int[] nums, int target) {
    int low = 0, high = nums.length - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target == nums[mid]) {
        return mid;
      }
      if (nums[mid] < nums[high]) {   // 右侧区间单调递增
        if (target > nums[mid] && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {                        // 左侧区间单调递增
        if (target < nums[mid] && target >= nums[low]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
    }
    return -1;
  }
}

