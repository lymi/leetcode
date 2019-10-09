/**
 * Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum
 * and return its sum.
 */

class Solution {
	public int maxSubArray(int[] nums) {
		int N = nums.length;
		int sum, max;
		sum = max = nums[0];

		for (int i = 1; i < N; i++) {
			sum = Math.max(sum + nums[i], nums[i]);
			if (sum > max) max = sum;
		}

		return max;
	}
}
