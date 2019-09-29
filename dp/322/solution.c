#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i] 代表构成面额i最少需要的硬币数
 * 2. DP转移方程:
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
  for (int j = 1; j <= amount; j++) {
    DP[j] = MAX;
  }
  
  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < N; j++) {
      if (i < coins[j]) continue;
      DP[i] = min(DP[i], 1 + DP[i-coins[j]]);
    }
  }

  return DP[amount] == MAX ? -1 : DP[amount];
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

