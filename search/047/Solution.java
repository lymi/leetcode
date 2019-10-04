import java.util.*;

class Solution {
  private List<List<Integer>> ret = new ArrayList<>();
  private boolean visited[];
  private int nums[];
  private int N; 

  public void backtrace(List<Integer> list) {
    if (list.size() == N) {
      ret.add(new ArrayList<>(list));
      return;
    }

    boolean duplicated;

    for (int i = 0; i < N; i++) {
      duplicated = false;
      for (int j = 0; j < i; j++) {
        if (i > 0 && nums[i] == nums[j] && !visited[j]) {
          duplicated = true;
          break;
        }
      }

      if (visited[i] || duplicated) {
        continue;
      }

      visited[i] = true;
      list.add(nums[i]);
      backtrace(list);
      list.remove(list.size() - 1);
      visited[i] = false;
    }
  }

  public List<List<Integer>> permuteUnique(int[] nums) {
    N = nums.length;
    if (N == 0) return ret; 
    this.nums = nums;
    visited = new boolean[N];
    backtrace(new ArrayList<Integer>());
    return ret;
  }

  public static void main(String args[]) { 
    int data[] = {1,2,1};
    List<List<Integer>> lists = new Solution().permuteUnique(data);
    
    for(List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

