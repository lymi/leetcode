/**
 *
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted
 * order, not the kth distinct element.
 */

class Solution {
	int partition (int[] nums, int low, int high) {
		int i = low, j = high, v = nums[i];
		while(i < j) {
			while(i < j && nums[j] >= v ) { j--; }
			nums[i] = nums[j];
			while(i < j && nums[i] <= v) { i++; }
			nums[j] = nums[i];
		}
		nums[i] = v;
		return i;
	}

	public int findKthLargest(int[] nums, int k) {
		int low = 0, high = nums.length - 1;
		k = nums.length - k;

		while(low < high) {
			int pivot = partition(nums, low, high);
			if (pivot == k) break;
			else if (pivot < k) low = pivot + 1;
			else high = pivot - 1;
		}
		return nums[k];
	}
}
