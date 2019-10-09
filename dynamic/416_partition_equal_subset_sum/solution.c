/**
 *
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such 
 * that the sum of elements in both subsets is equal.
 * ========================================================
 * 思路
 * 问题可转化为挑选数组中任意数字相加之和能否等于SUM / 2
 * 1. DP状态定义:
 *    DP[i][j] 代表取索引为0->i的任意数字相加之和能否为j,
 *    每个数字只能取一次，不计顺序
 * 2. DP转移方程:
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
  int DP[target+1];

  DP[0] = 1;
  for (int j = 1; j <= target; j++) {
    DP[j] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = target; j >= nums[i]; j--) {
      DP[j] = DP[j] || DP[j-nums[i]];
    }
  }

  return DP[target];
}

