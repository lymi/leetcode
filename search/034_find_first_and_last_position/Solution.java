/**
 *
 * Given an array of integers nums sorted in ascending order, 
 * find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

class Solution {
	private int findBoundary(int[] nums, int target, int type) {
		int N = nums.length;
		int low = 0, high = N-1, mid;
		while(low <= high) {
			mid = low + (high - low) / 2;
			if (nums[mid] > target) {
				high = mid - 1;
			} else if (nums[mid] < target) {
				low = mid + 1;
			} else {
				if (type == 0) { // 左边界
					if (mid == 0 || nums[mid-1] < nums[mid]) {
						return mid;
					}
					high = mid - 1;
				} else {         // 右边界
					if (mid == N-1 || nums[mid+1] > nums[mid]) {
						return mid;
					}
					low = mid + 1;    
				}
			}
		}
		return -1;
	}

	public int[] searchRange(int[] nums, int target) {
		int[] ret = {-1,-1};
		ret[0] = findBoundary(nums, target, 0);
		ret[1] = findBoundary(nums, target, 1);     
		return ret;
	}
}

