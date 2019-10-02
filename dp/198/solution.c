#include <stdio.h>
#include <assert.h>

/**
 * 1. DP[i]: 经过房屋 i 后(抢或不抢), 抢到钱的最大值
 * 2. DP[i] = max(DP[i-2] + nums[i], DP[i-1])
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

int main() {
  int nums1[5] = {1,3,1,3,100};
  assert(rob(nums1, 5) == 103);
  int nums2[2] = {0, 0};
  assert(rob(nums2, 2) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
}
