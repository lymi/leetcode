/**
 * Given two integers n and k, return all possible combinations
 * of k numbers out of 1 ... n
 */

import java.util.*;

class Solution {
  private int N, K;
  List<List<Integer>> ret = new ArrayList<>();

  public void backtrace(List<Integer> list, int start, int k) {
    if (list.size() == K) {
      ret.add(new ArrayList<Integer>(list));
      return;
    }

    for (int i = start; i <= N-k+1; i++) {
      list.add(i);
      backtrace(list, i+1, k-1);
      list.remove(list.size() - 1);
    }
  }

  public List<List<Integer>> combine(int n, int k) {
    N = n;
    K = k; 
    if (N == 0) return ret;
    backtrace(new ArrayList<Integer>(), 1, K);
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

