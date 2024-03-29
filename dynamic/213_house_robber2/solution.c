/**
 * You are a professional robber planning to rob houses along a
 * street. Each house has a certain amount of money stashed. All
 * houses at this place are arranged in a circle. That means the 
 * first house is the neighbor of the last one. Meanwhile, adjacent 
 * houses have security system connected and it will automatically
 * contact the police if two adjacent houses were broken into on the
 * same night.
 * Given a list of non-negative integers representing the amount of
 * money of each house, determine the maximum amount of money you can
 * rob tonight without alerting the police.
 * ===================================================================
 * 思路
 * 环形街区，开头与末尾相邻，可拆分为子问题:
 * 指定可抢劫房屋的范围[first, last], 最多能抢多少钱?
 *
 * 分别求出抢劫范围为[0, N-2] 和 [1, N-1]时抢钱的最大值，进行比较，
 * 较大的那个即为所求。
 *
 * 1. DP状态定义: DP[i]代表经过房屋i后(抢或不抢), 最多抢到的钱数
 * 2. DP转移方程：DP[i] = max(DP[i-1], DP[i-2] + nums[i])
 */

int max(int x, int y) {
  return x > y ? x : y;
}

int compute(int *nums, int first, int last) {
  if (first == last) return nums[first];
  int DP[last+1];
  DP[first] = nums[first];
  DP[first+1] = max(nums[first], nums[first+1]);
  
  for (int i = first+2; i <= last; i++) {
    DP[i] = max(DP[i-1], DP[i-2] + nums[i]);
  }
  
  return DP[last];
}

int rob(int *nums, int N) {
  if (N == 0) return 0;
  if (N == 1) return nums[0];
  return max(compute(nums, 0, N-2), compute(nums, 1, N-1));
}

