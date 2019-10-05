#include <stdio.h>
#include <assert.h>

/** 
 * 限定:
 * a. 每种面值的硬币可以选无限多
 * b. 相同的硬币不同的顺序算作一种选法, 即顺序不敏感
 *
 * 1. DP状态定义
 *    DP[j] 表示选择硬币构成面额j一共多少种选法
 * 2. DP转移方程
 *    自底向上递推, 初始时j = 1,
 *    DP[j] = SUM(DP[j-coins[i]])
 *
 * 注: 由于顺序不敏感，故将硬币的循环放在外层，避免重复计算，
 *     但本质上还是自底向上的递推，只是比较隐蔽。
 *     若不同的排列算作不同的选法, 则需将硬币的循环放在内层
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

