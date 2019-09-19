#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i][j]表示到第i+1天结束时的最大收益。
 *    j 表示是否持有股票, 0 -- 不持有, 1 -- 持有
 *
 * 2. DP转移方程:
 *    DP[i][0] = max(DP[i-1][0], DP[i-1][1] + prices[i] - fee)
 *    DP[i][1] = max(DP[i-1][1], DP[i-1][0] - prices[i]) 
 */

int max(int x, int y) {
  return x > y ? x : y;
}

int maxProfit(int* prices, int N, int fee) {
  int DP[N][2];

  DP[0][0] = 0;
  DP[0][1] = -prices[0];

  for (int i = 1; i < N; i++) {
    DP[i][0] = max(DP[i-1][0], DP[i-1][1] + prices[i] - fee);
    DP[i][1] = max(DP[i-1][1], DP[i-1][0] - prices[i]);
  }

  return DP[N-1][0];
}

int main() {
  int arr1[6] = {1,3,2,8,4,9};
  assert(maxProfit(arr1, 6, 2) == 8);

  printf("ALL TESTS PASSED!\n");
  return 0;
}
