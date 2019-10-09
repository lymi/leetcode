/**
 * You are given coins of different denominations and a total 
 * amount of money amount. Write a function to compute the fewest
 * number of coins that you need to make up that amount. If that amount 
 * of money cannot be made up by any combination of the coins, return -1.
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * =======================================
 * 思路
 * 1. DP状态定义:
 *    DP[i] 代表构成面额i最少需要的硬币数
 * 2. DP转移方程:
 *    采用自底向上递推的方式, 初始时i = 1
 *    DP[i] = 1 + min(i-coins[j])
 *                      (0 <= j < N)
 */   

int min(int x, int y) {
  return x < y ? x : y;
}

int coinChange(int *coins, int N, int amount) {
  int MAX = amount + 1;
  int DP[MAX];
  DP[0] = 0;

  for (int i = 1; i <= amount; i++) {
    DP[i] = MAX;
  }

  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < N; j++) {
      if (i >= coins[j]) {
        DP[i] = min(DP[i], 1 + DP[i-coins[j]]);
      }
    }
  }

  return DP[amount] == MAX ? -1 : DP[amount];
}

