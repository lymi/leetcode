import java.util.Arrays;

class Solution {
  /**
   * 将pairs中每个数组按第一个数字由小到大进行排序
   *
   * 1, DP状态定义:
   *    DP[i]: 对于索引 0 -> i(i: 0 -> N-1) 的pairs序列, 在选中 i 的情况下,
   *    能够构成的最长链条长度。
   * 2, DP转移方程:
   *    DP[i] = max{DP[j]} + 1   (pairs[i]放在链尾)   (j: 0 -> i-1)
   * 3, 最终结果 max{DP[i]} (i: 0 -> N-1)
   */
  public static int findLongestChain(int[][] pairs) {
    Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
    int N = pairs.length;
    int DP[] = new int[N], max, ret = 0;
    DP[0] = 0;

    for(int i = 0; i < N; i++) {
      max = 0;
      for (int j = 0; j < i; j++) {
        if (max < DP[j] && pairs[i][0] > pairs[j][1]) {
          max = DP[j];
        }
      }
      DP[i] = 1 + max;
    }

    for (int i = 0; i < N; i++) {
      if (ret < DP[i]) ret = DP[i];
    }

    return ret;
  }

  public static void main(String args[]) {
    int pairs1[][] = {{1,2}, {2,3}, {3,4}};
    int pairs2[][] = {{3,4}, {2,3}, {1,2}};

    assert(findLongestChain(pairs1) == 2);
    assert(findLongestChain(pairs2) == 2);

    System.out.println("ALL TESTS PASSED!");
  }
}

