/** 
 *
 * You are given coins of different denominations and a total
 * amount of money. Write a function to compute the number of
 * combinations that make up that amount. You may assume that
 * you have infinite number of each kind of coin.
 * =======================================================
 * 思路
 * 1. DP状态定义
 *    DP[i] 表示选择硬币构成面额i一共多少种选法
 * 2. DP转移方程
 *    自底向上递推, 初始时i = 1,
 *    DP[i] = SUM(DP[i-coins[j]])
 *
 * 注: 相同硬币不同排列方式算作同一种选法，故将硬币的循环放
 *     在外层，避免重复计算，但本质上还是自底向上的递推，只
 *     是比较隐蔽。若不同的排列算作不同的选法, 则需将硬币的
 *     循环放在内层，保证每一种排列都能计入。
 */

int change(int amount, int *coins, int N) {
  int DP[amount+1];

  DP[0] = 1;
  for (int i = 1; i <= amount; i++) {
    DP[i] = 0;
  }

  for (int j = 0; j < N; j++) {
    for (int i = coins[j]; i <= amount; i++) {
      DP[i] += DP[i-coins[j]];
    }
  }

  return DP[amount];
}

