#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i][j] 代表取前i+1个数中任意多个数字相加之和能否为j
 *    0 -- 不能，1 -- 能
  2. DP转移方程:
 *    DP[i][j] = DP[i-1][j] || DP[i-1][j-nums[i]]
 *    空间优化后:
 *    DP[j] = DP[j] || DP[j-nums[i]]
 */
int canPartition(int* nums, int N) {
  if (N <= 1) return 0;
  int sum = 0;
  for (int i = 0; i < N; i++) sum += nums[i];
  if (sum % 2 != 0) return 0;
  int target = sum / 2;
  int DP[N][target+1];

  DP[0][0] = 1;
 
  for (int j = 1; j <= target; j++) {
    DP[0][j] = nums[0] == j ? 1 : 0;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= target; j++) {
      if (j >= nums[i]) {
        DP[i][j] = DP[i-1][j] || DP[i-1][j-nums[i]];
      } else {
        DP[i][j] = DP[i-1][j];
      }
    }
  }

  return DP[N-1][target];

  /*********** 空间优化 **************
  int DP[target+1];

  for (int i = 1; i <= target; i++) {
    DP[i] = 0;
  }
  
  DP[0] = 1; 

  for (int i = 1; i < N; i++) {
    for (int j = target; j >= nums[i]; j--) {
      DP[j] = DP[j] || DP[j-nums[i]];
    }
  }

  return DP[target];
  ************************************/
}

int main() {
  int arr1[4] = {1,5,11,5};
  assert(canPartition(arr1, 4) == 1);
  int arr2[4] = {1,2,3,5};
  assert(canPartition(arr2, 4) == 0);
  int arr3[3] = {1,2,5};
  assert(canPartition(arr3, 3) == 0);
  int arr4[4] = {1,1,1,1};
  assert(canPartition(arr4, 4) == 1);
  int arr5[6] = {1,3,5,5,5,5};
  assert(canPartition(arr5, 6) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
} 

