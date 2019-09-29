#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义
 *    DP[i] 表示选择硬币构成面额i一共多少种选法, 每种面值的硬币可以选无限多
 * 2. DP转移方程
 *    DP[i] = SUM(DP[i-coins[j]])
 */
int change(int amount, int *coins, int N) {
  int DP[amount+1];

  DP[0] = 1;
  for (int i = 1; i <= amount; i++) {
    DP[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = coins[i]; j <= amount; j++) {
      DP[j] += DP[j-coins[i]];
    }
  }

  return DP[amount];
}

int main() {
  int coins1[3] = {1,2,5};
  int coins2[1] = {2};
  int coins3[1] = {10};
  assert(change(5, coins1, 3) == 4);
  assert(change(3, coins2, 1) == 0);
  assert(change(10, coins3, 1) == 1);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

