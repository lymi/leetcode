#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * 1. DP状态定义:
 *    DP[k][i]表示进行最多k次交易后第i+1天的最大收益。
 *    其中 k -> [0, N/2], i -> [0, N-1]
 * 2. DP转移方程:
 *    DP[k][i] = max(DP[k-1][i], DP[k][i-1], max(DP[k-1][j] - prices[j] + prices[i] - fee))
 *             = max(DP[k-1][i], DP[k][i-1], max(DP[k-1][j] - prices[j]) + prices[i] - fee)
 *                                           |-------- localMax -------|
 *                                                    0 <= j < i
 */

int max(int x, int y, int z) {
  int r = x > y ? x : y;
  return r > z ? r : z;
}

int maxProfit(int* prices, int N, int fee) {
  int K = N / 2;
  int **DP; 

  for (int k = 0; k <= K; k++) {
    DP = (int **)malloc((K+1) * sizeof(int *));
  }

  for (int i = 0; i < N; i++) {
    *(DP + i) = (int *)malloc(N * sizeof (int));
  }


  for (int k = 0; k <= K; k++) {
    for (int i = 0; i < N; i++) {
      DP[k][i] = 0;
    }
  }

  for (int k = 1; k <= K; k++) {
    int localMax = -prices[0];
    for (int i = 1; i < N; i++) {
      if (DP[k-1][i-1] - prices[i-1] > localMax) {
        localMax = DP[k-1][i-1] - prices[i-1];
      }

      DP[k][i] = max(DP[k-1][i], DP[k][i-1], localMax + prices[i] - fee);
    }
  }

  return DP[K][N-1];
}

int main() {
  int arr1[6] = {1,3,2,8,4,9};
  assert(maxProfit(arr1, 6, 2) == 8);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

