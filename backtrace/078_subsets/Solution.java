/**
 * Given a set of distinct integers, nums, return all
 * possible subsets(the power set).
 * Note: The solution set must not contain duplicate subsets.
 */

import java.util.*;

class Solution {
  private List<List<Integer>> ret = new ArrayList<>();
  private List<Integer> temp = new ArrayList<>();
  private int[] nums;
  private int N;

  public void traceback(int start) {
    ret.add(new ArrayList<Integer>(temp));
    if (start >= N) return;

    for (int i = start; i < N; i++) {
      temp.add(nums[i]);
      traceback(i+1);
      temp.remove(temp.size() - 1);
    }
  }

  public List<List<Integer>> subsets(int[] nums) {
    N = nums.length;
    this.nums = nums;
    traceback(0);
    return ret;
  }

  public static void main(String args[]) {
    int nums[] = {1,2,3};
    List<List<Integer>> lists = new Solution().subsets(nums);

    for (List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

