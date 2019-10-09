/**
 * Given a positive integer n, break it into the sum of at least
 * two positive integers and maximize the product of those integers.
 * Return the maximum product you can get.
 * ==========================================================
 * 思路
 * 1. DP专题定义: DP[i] 代表i分解后乘积的最大值
 * 2. DP转移方程: DP[i] = max{ max(j * DP[i-j], j * (i-j)) }  (j: 1 -> i)
 */

int max(int x, int y) {
  return x > y ? x : y;
}

int integerBreak(int n) {
  int DP[n+1], localmax, temp;
  DP[0] = 0;

  for (int i = 1; i <= n; i++) {
    localmax = 0;
    for (int j = 1; j < i; j++) {
      temp = max(j * DP[i-j], j * (i-j));
      if (localmax < temp) {
        localmax = temp;
      }
    }

    DP[i] = localmax;
  }

  return DP[n];
}

