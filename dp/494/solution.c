#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i][j] 表示在前i+1个数字中选择任意多个(包括0个)数字, 
 *    相加结果等于 j 最多有多少种选法。
 * 2. DP转移方程:
 *    DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i]];
 *    空间优化后:
 *    DP[j] = DP[j] + DP[j-nums[i]]
 */
int findTargetSumWays(int* nums, int N, int S) {
  int sum = 0;
  for (int i = 0; i < N; i++) sum += nums[i];
  if (sum < S || (sum - S) % 2 != 0) return 0;
  int target = (sum - S) / 2;
  int DP[N][target+1];

  if (nums[0] == 0) {
    DP[0][0] = 2;
  } else {
    DP[0][0] = 1;
  }

  for (int j = 1; j <= target; j++) {
    DP[0][j] = nums[0] == j ? 1 : 0;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= target; j++) {
      if (j >= nums[i]) {
        DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i]];
      } else {
        DP[i][j] = DP[i-1][j];
      }
    }
  }

  return DP[N-1][target];

  /************* 空间优化 ***************
  int DP[target+1];

  for (int i = 1; i <= target; i++) {
    DP[i] = 0;
  }

  DP[0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = target; j >= nums[i]; j--) {
      DP[j] = DP[j] + DP[j-nums[i]];
    } 
  }

  return DP[target];
  ***************************************/
}

int main() {
  int nums1[5] = {1,1,1,1,1};
  assert(findTargetSumWays(nums1, 5, 3) == 5);
  printf("===============\n");
  int nums2[9] = {0,0,0,0,0,0,0,0,1};
  assert(findTargetSumWays(nums2, 9, 1) == 256);

  printf("ALL TESTS PASSED!\n");
  return 0;
}
