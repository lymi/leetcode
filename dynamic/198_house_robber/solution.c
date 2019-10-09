/**
 *
 * You are a professional robber planning to rob houses along a 
 * street. Each house has a certain amount of money stashed, the only 
 * constraint stopping you from robbing each of them is that adjacent 
 * houses have security system connected and it will automatically 
 * contact the police if two adjacent houses were broken into on 
 * the same night.
 * Given a list of non-negative integers representing the amount
 * of money of each house, determine the maximum amount of money
 * you can rob tonight without alerting the police.
 * ===================================================
 * 思路
 * 1. DP状态定义: DP[i]代表经过房屋i后(抢或不抢),抢到钱的最大值
 * 2. DP[i] = max(DP[i-2] + nums[i], DP[i-1])
 *                     (抢)           (不抢) 
 */

int max(int x, int y) {
  return x > y ? x : y;
}

int rob(int *nums, int N) {
  if (N == 0) return 0;
  if (N == 1) return nums[0];
  int DP[N];
  DP[0] = nums[0];
  DP[1] = max(nums[0], nums[1]);

  for (int i = 2; i < N; i++) {
    DP[i] = max(DP[i-2] + nums[i], DP[i-1]);
  }

  return DP[N-1];
}

