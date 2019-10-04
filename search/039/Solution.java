import java.util.*;

class Solution {
  private int target, N;
  private List<List<Integer>> ret = new ArrayList<>();
  private int[] candidates;

  public void traceback(List<Integer> list, int start) {
    int sum = 0;
    for (int i : list) {
      sum += i;
    }
    if (sum > target) return;
    if (sum == target) {
      ret.add(new ArrayList(list));
      return;
    }

    for (int i = start; i < N; i++) {
      list.add(candidates[i]);
      traceback(list, i);
      list.remove(list.size() - 1);
    }
  }

  public List<List<Integer>> combinationSum(int[] candidates, int target) {
    N = candidates.length;
    if (N == 0) return ret;
    this.target = target;
    this.candidates = candidates;

    traceback(new ArrayList<Integer>(), 0);

    return ret;
  }

  public static void main(String args[]) {
    int candidates[] = {2,3,5};
    List<List<Integer>> lists = new Solution().combinationSum(candidates, 8);
    for (List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

