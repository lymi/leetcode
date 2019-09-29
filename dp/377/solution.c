#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i] 代表和为i的组合数
 * 2. DP转移方程:
 *    DP[i] = SUM(DP[i-nums[j]])
 *                    (0 <= j < N)
 */
int combinationSum4(int *nums, int N, int target) {
  int DP[target+1];

  DP[0] = 1;
  for (int i = 1; i <= target; i++) {
    DP[i] = 0;
  }

  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < N; j++) {
      if (i >= nums[j]) {
        DP[i] += DP[i-nums[j]];
      }
    }
  }

  return DP[target];
}

int main() {
  int nums[3] = {1,2,3};
  assert(combinationSum4(nums, 3, 4) == 7);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

