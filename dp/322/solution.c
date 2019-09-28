#include <stdio.h>
#include <assert.h>

#define POS_MAX 999999

/**
 * 1. DP状态定义:
 *    DP[i][j] 代表当只使用前i+1个面值的硬币去组成面额j需要的最少硬币数
 * 2. DP转移方程:
 *    DP[i][j] = min(DP[i-1][j], 1 + DP[i-1][j-coins[i]])
 *    空间优化:
 *    DP[j] = min(DP[j], 1 + DP[j-coins[i]])
 */

int min(int x, int y) {
  return x < y ? x : y;
}

int coinChange(int *coins, int N, int amount) {
  int DP[amount+1];

  DP[0] = 0;
  for (int j = 1; j <= amount; j++) {
    DP[j] = POS_MAX;
  }

  for (int i = 0; i < N; i++) {
    for (int j = coins[i]; j <= amount; j++) {
      DP[j] = min(DP[j], 1 + DP[j-coins[i]]);
    }
  }

  if (DP[amount] == POS_MAX) {
    return -1;
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

