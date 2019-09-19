#include <stdio.h>
#include <assert.h>

#define MAX_INF 9999999 

/**
 * 1. DP状态定义:
 *    DP[i] 表示和为 i 时需要的最少数组元素的个数
 * 2. DP转移方程:
 *    DP[i] = 1 + min{DP[i - nums[j]]}
 *                         (0 <= j <= N-1)
 */

int canPartition(int* nums, int N){
  if (N <= 1) return 0;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += nums[i];
  }

  if (sum % 2 != 0) {
    return 0;
  }

  int MID = sum / 2;
  int DP[MID + 1];

  for (int i = 0; i <= MID; i++) {
    DP[i] = MAX_INF;
    for (int j = 0; j < N; j++) {
      if (i == nums[j]) {
        DP[i] = 1;
      }
    }
  }

  for (int i = 1; i <= MID; i++) {
    int min = MAX_INF;
    for (int j = 0; j < N; j++) {
      if (i > nums[j] && DP[i-nums[j]] < MAX_INF && min > DP[i-nums[j]]) {
        min = DP[i - nums[j]];
      }
    }

    if (min < MAX_INF) {
      DP[i] = 1 + min;
    }
  }

  if (DP[MID] < MAX_INF) {
    return 1;
  }
  return 0;
}

int main() {
  int arr1[4] = {1,5,11,5};
  assert(canPartition(arr1, 4) == 1);
  int arr2[4] = {1,2,3,5};
  assert(canPartition(arr2, 4) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
} 

