import java.util.*;

class Solution {
  private List<List<Integer>> ret = new ArrayList<>();

  public void traceback(List<Integer> list, int start, int k, int target) {
    if (target == 0 && k == 0) {
      ret.add(new ArrayList<>(list));
      return;
    }

    if (target < 0 || k < 0) return;

    for (int i = start; i < 10; i++) {
      list.add(i);
      traceback(list, i+1, k-1, target-i);
      list.remove(list.size() - 1);
    }
  }

  public List<List<Integer>> combinationSum3(int k, int target) {
    if (k == 0) return ret;
    traceback(new ArrayList<Integer>(), 1, k, target);
    return ret;
  }

  public static void main(String args[]) {
    List<List<Integer>> lists = new Solution().combinationSum3(3, 9);
    for (List<Integer> list : lists) {
      for (int i : list) {
        System.out.print(i + " ");
      }
      System.out.println();
    }
  }
}

