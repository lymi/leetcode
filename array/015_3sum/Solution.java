/**
 * Given an array nums of n integers, are there elements 
 * a, b, c in nums such that a + b + c = 0? Find all unique
 * triplets in the array which gives the sum of zero.
 */

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    Arrays.sort(nums);
    int N = nums.length;
    List<List<Integer>> ret = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      if (i > 0 && nums[i] == nums[i-1]) continue;

      int j = i + 1, k = N - 1;

      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          ret.add(Arrays.asList(nums[i], nums[j], nums[k]));
          j++;
          k--;
          while (j < k && nums[j] == nums[j-1]) j++;
          while (j < k && nums[k] == nums[k+1]) k--; 
        } else if (nums[i] + nums[j] + nums[k] < 0) {
          j++;
        } else {
          k--;
        }
      }
    }

    return ret;
  }
}

