/**
 *
 * Given an array with n integers, your task is to check if it
 * could become non-decreasing by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] 
 * holds for every i (1 <= i < n).
 */

class Solution {
	public boolean checkPossibility(int[] nums) {
		int N = nums.length;
		if (N <= 2) return true;
		boolean flag = false;

		for (int i = 0; i < N-1; i++) {
			if (nums[i] <= nums[i+1]) {
				continue;
			}
			// nums[i] > nums[i+1]
			if (flag) return false;
			flag = true;
			if (i == 0) nums[i] = nums[i+1];        // 开始时尽可能小
			else if (i == N-2) nums[i+1] = nums[i]; // 结束时尽可能大
			else if (nums[i+1] < nums[i-1])	nums[i+1] = nums[i]; 
      else nums[i] = nums[i+1]; 
		}

		return true;
	}
}
