/**
 *
 * Given an unsorted array of integers, find the length of longest 
 * increasing subsequence.
 * Note:
 * There may be more than one LIS combination, it is only necessary
 * for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * ================================================================
 * 思路
 * 1. DP状态定义:
 *    DP[i]: 对于给定序列0 -> i (i: 0 -> N-1)，在选中元素 i 的情况下，
 *    最长递增子序列的长度
 * 2. DP转移方程:
 *    DP[i] = max{DP[j]} + 1   (nums[i] > nums[j])   (j: 0 -> i-1)
 *    最终结果: max{DP[i]}  (i: 0 -> N-1)
 */

int lengthOfLIS(int *nums, int N) {
  if (N <= 0) return 0;
  int DP[N], max, ret = 0;

  DP[0] = 0;
  
  for (int i = 0; i < N; i++) {
    max = 0;
    for (int j = 0; j < i; j++) {
      if (max < DP[j] && nums[i] > nums[j]) {
        max = DP[j];
      }
    }
    DP[i] = max + 1;
  }

  for (int i = 0; i < N; i++) {
    if (ret < DP[i]) ret = DP[i];
  }

  return ret;
}

