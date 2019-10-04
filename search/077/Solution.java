import java.util.*;

class Solution {
  private int N, K;
  private boolean[] visited;
  List<List<Integer>> ret = new ArrayList<>();

  public void backtrace(List<Integer> list, int start) {
    if (list.size() == K) {
      ret.add(new ArrayList<Integer>(list));
    }

    for (int i = start; i <= N; i++) {
      if (visited[i]) {
        return;
      }

      visited[i] = true;
      list.add(i);
      backtrace(list,start+1);
      list.remove(list.size() - 1);
      visited[i] = false;
    }
  }

  public List<List<Integer>> combine(int n, int k) {
    N = n;
    K = k; 
    if (N == 0) return ret;
    visited = new boolean[N+1];
    backtrace(new ArrayList<Integer>(), 1);
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

