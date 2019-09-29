#include <stdio.h>
#include <assert.h>

/**
 * 动态规划求解
 *
 * 思路1: 自底向上递推
 *    DP[i] 代表和为i的组合数
 *    DP[i] = SUM(DP[i-nums[j]]), 初始i = 1。
 *    该方法如果target非常大, 而DP[target]不大，可能会出现计算过程中
 *    的一些中间值指数倍增长，很快超过int的范围而报错。
 *
 * 思路2: 自顶向下递归
 *    DP[i] = SUM(DP[i-nums[j]]), 初始i = amount
 */

int compute(int *nums, int N, int remain, int *DP) {
  if (remain < 0) return 0;
  if (DP[remain] != -1) return DP[remain];

  int ret = 0;
  for (int i = 0; i < N; i++) {
    ret += compute(nums, N, remain-nums[i], DP);
  }

  DP[remain] = ret;
  return ret;
}

int combinationSum4(int *nums, int N, int target) {
  int DP[target+1];
  DP[0] = 1;
  for (int i = 1; i <= target; i++) {
    DP[i] = -1;
  }
  return compute(nums, N, target, DP);
}

int main() {
  int nums1[3] = {1,2,3};
  assert(combinationSum4(nums1, 3, 4) == 7);
  int nums2[3] = {3, 33, 333};
  assert(combinationSum4(nums2, 3, 10000) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

