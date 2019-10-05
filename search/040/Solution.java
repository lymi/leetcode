import java.util.*;

class Solution {
  private List<List<Integer>> ret = new ArrayList<>();
  private int[] candidates;
  private boolean[] visited;
  private int N;

  public void traceback(List<Integer> list, int start, int target) {
    if (target == 0) {
      ret.add(new ArrayList<>(list));
      return;
    }

    if (target < 0) return;
    boolean duplicated;

    for (int i = start; i < N; i++) {
      duplicated = false;

      for (int j = 0; j < i; j++) {
        // 重复的数字只允许出现在同一递归链中，不能出现在不同的递归链中。
        if (candidates[i] == candidates[j] && !visited[j]) {
          duplicated = true;
          break;
        }
      }

      if (duplicated) {
        continue;
      }

      list.add(candidates[i]);
      visited[i] = true;
      traceback(list, i+1, target-candidates[i]);
      visited[i] = false;
      list.remove(list.size() - 1);
    }
  }

  public List<List<Integer>> combinationSum2(int[] candidates, int target) {
    N = candidates.length;
    if (N == 0) return ret;
    this.candidates = candidates;
    visited = new boolean[N];

    traceback(new ArrayList<Integer>(), 0, target);

    return ret;
  }

  public static void main(String args[]) {
    int candidates[] = {10,1,2,7,6,1,5};
    List<List<Integer>> lists = new Solution().combinationSum2(candidates, 8);
    for (List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

