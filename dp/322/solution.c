#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i] 代表构成面额i最少需要的硬币数
 * 2. DP转移方程:
 *    DP[i] = 1 + min(DP[i-coins[j]])
 *                   (0 <= j < N)
 */
int coinChange(int *coins, int N, int amount) {
  int DP[amount+1], min, dp;

  DP[0] = 0;
  for (int i = 1; i <= amount; i++) {
    DP[i] = -1;
  }

  for (int i = 1; i <= amount; i++) {
    min = -1;
    for (int j = 0; j < N; j++) {
      if (i < coins[j]) continue;
      dp = DP[i-coins[j]];
      if (dp == -1) continue;
      if (min == -1 || min > dp) {
        min = dp;
      }
    }
    
    if (min > -1) {
      DP[i] = 1 + min;
    }
  }

  return DP[amount];
}

int main() {
  int coins1[3] = {1,2,5};
  assert(coinChange(coins1, 3, 11) == 3);
  int coins2[1] = {2};
  assert(coinChange(coins2, 1, 3) == -1);
  int coins3[1] = {1};
  assert(coinChange(coins3, 1, 0) == 0);
  int coins4[4] = {186, 419, 83, 408};
  assert(coinChange(coins4, 4, 6249) == 20);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

