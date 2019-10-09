/**
 *
 * Given a set of candidate numbers (candidates) (without duplicates) 
 * and a target number (target), find all unique combinations in candidates
 * where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 */
 
import java.util.*;

class Solution {
  private int N;
  private List<List<Integer>> ret = new ArrayList<>();
  private int[] candidates;

  public void traceback(List<Integer> list, int start, int target) {
    if (target == 0) {
      ret.add(new ArrayList<>(list));
      return;
    }

    if (target < 0) return;

    for (int i = start; i < N; i++) {
      list.add(candidates[i]);
      traceback(list, i, target-candidates[i]);
      list.remove(list.size() - 1);
    }
  }

  public List<List<Integer>> combinationSum(int[] candidates, int target) {
    N = candidates.length;
    if (N == 0) return ret;
    this.candidates = candidates;

    traceback(new ArrayList<Integer>(), 0, target);

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

