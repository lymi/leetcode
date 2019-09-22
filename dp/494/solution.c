#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i][j] 表示在前i+1个数字中选择任意多个数字, 
 *    相加等于j最多j有多少种选法。
 * 2. DP转移方程:
 *    DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i]];
 */

int findTargetSumWays(int* nums, int N, int S) {
  int sum = 0;

  for (int i = 0; i < N; i++) sum += nums[i];
  if (sum < S || (sum - S) % 2 != 0) return 0;

  int target = (sum - S) / 2;
  int DP[N][target + 1];

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= target; j++) {
      if (j == nums[i]) {
        DP[i][j] = 1;
      } else {
        DP[i][j] = 0;
      }
    }
    DP[i][0] = 1;
  }

  for (int i = 1; i < N; i++) {
    for (int j = target; j >= nums[i]; j--) {
      DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i]];
    }
  }

  return DP[N-1][target];
}

int main() {
  int nums[5] = {1, 1, 1, 1, 1};
  assert(findTargetSumWays(nums, 5, 3) == 5);
  printf("ALL TESTS PASSED!\n");
  return 0;
}

