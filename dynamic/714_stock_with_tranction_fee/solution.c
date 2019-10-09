/**
 *
 * Your are given an array of integers prices, for which
 * the i-th element is the price of a given stock on day i;
 * and a non-negative integer fee representing a transaction fee.
 * You may complete as many transactions as you like, but
 * you need to pay the transaction fee for each transaction.
 * You may not buy more than 1 share of a stock at a time
 * (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 * =====================================================
 * 思路
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

