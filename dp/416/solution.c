#include <stdio.h>
#include <assert.h>

#define MAX_INF 1000

/**
 * 如果所有元素之和为奇数，则一定不能划分成和相等的两部分。
 * 如果所有元素之和为偶数，则问题可转化为能否找到任意多个
 * 元素相加结果为SUM / 2，每个元素只能使用一次。
 *
 * 1. DP状态定义:
 *    DP[m] 表示和为 m 时需要的最少数组元素的个数
 *    used[m][i] 表示和为 m 时元素 i 是否被使用过, 0 -- 未使用, 1 -- 已使用
 * 2. DP转移方程:
 *    DP[m] = 1 + min{DP[m - nums[i]] != 0 && used[m - nums[i]][i] == 0}
 *                         (0 <= i <= N-1)
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
  int used[MID+1][N];

  for (int m = 0; m <= MID; m++) {
    DP[m] = 0;
    for (int i = 0; i < N; i++) {
      used[m][i] = 0;

      if (m == nums[i]) {
        DP[m] = 1;
        used[m][i] = 1;
        continue;
      }
    }
  }

  for (int m = 1; m <= MID; m++) {
    if (DP[m] == 1) {
      continue;
    }

    int min = MAX_INF;
    int minIdx = 0;

    for (int i = 0; i < N; i++) {
      if (m > nums[i] && DP[m-nums[i]] != 0 &&
          used[m-nums[i]][i] == 0 && min > DP[m-nums[i]]) {
        min = DP[m - nums[i]];
        minIdx = i;
      }
    }

    if (min < MAX_INF) {
      DP[m] = 1 + min;
      used[m][minIdx] = 1;
    }
  }

  if (DP[MID] > 0) {
    return 1;
  }
  return 0;
}

int main() {
  /*
  int arr1[4] = {1,5,11,5};
  assert(canPartition(arr1, 4) == 1);
  int arr2[4] = {1,2,3,5};
  assert(canPartition(arr2, 4) == 0);
  */
  int arr3[3] = {1,2,5};
  assert(canPartition(arr3, 3) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
} 

