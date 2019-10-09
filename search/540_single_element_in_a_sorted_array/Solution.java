/**
 *
 * You are given a sorted array consisting of only integers where
 * every element appears exactly twice, except for one element which 
 * appears exactly once. Find this single element that appears only once.
 * Note: Your solution should run in O(log n) time and O(1) space.
 */ 

class Solution {
	public int singleNonDuplicate(int[] nums) {
		int N = nums.length;
		int low = 0, high = N - 1, mid;

		while(low <= high) {
			mid = low + (high - low) / 2;
			if (mid < N - 1 && nums[mid+1] == nums[mid]) {
				if (mid % 2 == 0) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			} else if (mid > 0 && nums[mid-1] == nums[mid]) {
				if (mid % 2 == 0) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			} else return nums[mid];
		}
		return -1;
	}
}

