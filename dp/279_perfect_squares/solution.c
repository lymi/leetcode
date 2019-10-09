/**
 * Given a positive integer n, find the least number of perfect
 * square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 * ===========================================================
 * 思路
 * 1. DP状态定义: DP[i]代表将数字 i 分解成几个数的平方和所需要的最少数字个数。
 * 2. DP转移方程:DP[i] = min{ DP[i-j*j] } + 1
 *                             (0 <= j <= sqrt(i))
 */

int numSquares(int n) {
  int MAX = n + 1;
  int DP[n+1], temp;

  DP[0] = 0;

  for (int i = 1; i < MAX; i++) {
    DP[i] = MAX;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sqrt(i); j++) {
      temp = DP[i-j*j] + 1;
      if (DP[i] > temp) {
        DP[i] = temp;
      }
    }
  }

  return DP[n];
}

