/**
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) return nums[0];
        
        int low = 0, high = nums.length - 1, mid;
        
        if (nums[0] < nums[high]) return nums[0];
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid+1]) return nums[mid+1];
            if (nums[mid-1] > nums[mid]) return nums[mid];
            
            if (nums[mid] > nums[0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
}
