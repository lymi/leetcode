/**
 *
 * Given an array with n objects colored red, white or blue,
 * sort them in-place so that objects of the same color are
 * adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the
 * color red, white, and blue respectively.
 */

class Solution {
	public void swap(int[] nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	public void sortColors(int[] nums) {
		int N = nums.length;
		int curr = 0, zero = 0, two = N - 1;

		while (curr <= two) {
			if (nums[curr] == 0) {
				swap(nums, curr, zero);
				zero++;
				curr++;
			} else if (nums[curr] == 2) {
				swap(nums, curr, two);
				two--;
			} else {
				curr++;
			}
		}
	}
}

