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

      while(i < N-1 && nums[i] == nums[i+1]) { i++; }
    }
  }

  public List<List<Integer>> subsetsWithDup(int[] nums) {
    N = nums.length;
    Arrays.sort(nums);
    this.nums = nums;
    traceback(0);
    return ret;
  }

  public static void main(String args[]) {
    int nums[] = {1,2,2};
    List<List<Integer>> lists = new Solution().subsetsWithDup(nums);

    for (List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

