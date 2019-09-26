#include <stdio.h>

/**
 * 可以拆分成两个子问题：
 * a. 如果 K >= N/2, 则问题转化为 "交易任意多次可获得的最大收益"。
 *    由于一个交易日内可以先卖出之前持有的股票，再买入当天的股票, 
 *    故不限次数的情况下，只要能盈利就进行交易。
 *
 * b. 如果 K < N/2, 则问题转化为 "最多交易K次可获得的最大收益"。
 *    即求在只进行k(0 ~ K)次交易的情况下，能够获得最大收益的最大值。
 *
 * 问题a再P121中已解决，对于b使用动态规划:
 * 1. DP状态定义:
 *    DP[k][i]代表交易k次时截止到第i+1天的最大收益值。
 *    其中i->[0, N-1], k->[0, K]。
 * 2. DP转移方程:
 *    DP[k][i] = max(DP[k-1][i], DP[k][i-1], max(DP[k-1][j] - prices[j] + prices[i]))
 *             = max(DP[k-1][i], DP[k][i-1], prices[i] + max(DP[k-1][j] - prices[j]))
 *                                                       |------- localMax --------|
 *                                                              (0 <= j < i)
 */

int max(int x, int y, int z) {
  int ret = x > y ? x : y;
  return ret > z ? ret : z;
}

int maxProfit(int K, int *prices, int N) {
  if (K <=0 || N <= 0) return 0;

  int ret = 0;

  if (K >= N/2) {
    for (int i = 1; i < N; i++) {
      if (prices[i] > prices[i-1]) {
        ret += prices[i] - prices[i-1];
      }
    }
    return ret;
  }

  int DP[K+1][N+1];

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
      DP[k][i] = max(DP[k-1][i], DP[k][i-1], prices[i] + localMax);
    }
  }

  return DP[K][N-1];
}

int main() {
  int arr1[3] = {2,4,1};
  printf("%d\n", maxProfit(2, arr1, 3));
  int arr2[6] = {3,2,6,5,0,3};
  printf("%d\n", maxProfit(2, arr2, 6));
  
  return 0;
}

