/**
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, 
 * and a target, S. Now you have 2 symbols + and -. For each integer,
 * you should choose one from + and - as its new symbol.
 * Find out how many ways to assign symbols to make sum of integers
 * equal to target S. 
 * ================================================================
 * 思路
 * 1. DP状态定义:
 *    DP[i][j] 表示在前i+1个数字中选择任意数字, 每个数字只能选一次,
 *    相加结果等于j最多有多少种选法。
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
}

