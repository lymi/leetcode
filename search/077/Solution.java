import java.util.*;

class Solution {
  private int N, K;
  private boolean[] visited;
  List<List<Integer>> ret = new ArrayList<>();

  public void backtrace(List<Integer> list) {
    if (list.size() == K) {
      ret.add(new ArrayList<Integer>(list));
    }

    for (int i = 1; i <= N; i++) {
      if (visited[i]) {
        return;
      }

      visited[i] = true;
      list.add(i);
      backtrace(list);
      list.remove(list.size() - 1);
      visited[i] = false;
    }
  }

  public List<List<Integer>> combine(int n, int k) {
    N = n;
    K = k; 
    if (N == 0) return ret;
    visited = new boolean[N+1];
    backtrace(new ArrayList<Integer>());
    return ret;
  }

  public static void main(String args[]) {
    List<List<Integer>> lists = new Solution().combine(4, 2);
    for (List<Integer> list : lists) {
      for (int ele : list) {
        System.out.print(ele + " ");
      }
      System.out.println();
    }
  }
}

