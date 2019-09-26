#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义
 *    DP[i] 表示构成面额 i 一共多少种组合方式。
 * 2. DP转移方程
 *    DP[i] = SUM(DP[i-coins[j]])
 *    为避免重复计算，将 j 作为外层循环
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

