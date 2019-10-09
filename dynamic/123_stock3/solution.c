/**
 *
 * Say you have an array for which the ith element is the
 * price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete at most two transactions.
 * Note: You may not engage in multiple transactions at the 
 * same time (i.e., you must sell the stock before you buy again).
 * ================================================================
 * 思路同188，只需将 K 替换成2。
 */

int max(int x, int y, int z) {
  int ret = x > y ? x : y;
  return ret > z ? ret : z;
}

int maxProfit(int *prices, int N) {
  if (N <= 0) return 0;

  int ret = 0;

  if (N <= 4) {
    for (int i = 1; i < N; i++) {
      if (prices[i] > prices[i-1]) {
        ret += prices[i] - prices[i-1];
      }
    }
    return ret;
  }

  int DP[3][N+1];
  for (int k = 0; k <= 2; k++) {
    for (int i = 0; i < N; i++) {
      DP[k][i] = 0;
    }
  }
 
  for (int k = 1; k <= 2; k++) {
    int localMax = -prices[0];

    for (int i = 1; i < N; i++) {
      if (DP[k-1][i-1] - prices[i-1] > localMax) {
        localMax = DP[k-1][i-1] - prices[i-1]; 
      }

      DP[k][i] = max(DP[k-1][i], DP[k][i-1], prices[i] + localMax);
    }
  }

  return DP[2][N-1];
}

