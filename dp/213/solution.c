#include <stdio.h>
#include <assert.h>

/**
 * 问题可简化为给定抢劫房屋的起点和终点，最多能抢多少钱
 *
 * 1. DP[i]: 经过房屋i后(抢或不抢), 最多抢到的钱数
 * 2. DP[i] = max(DP[i-1], DP[i-2] + nums[i]) 
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

int main() {
  int nums1[3] = {2,3,2};
  int nums2[4] = {1,2,3,1};
  int nums3[2] = {1,3};
  assert(rob(nums1, 3) == 3);
  assert(rob(nums2, 4) == 4);
  assert(rob(nums3, 2) == 3);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

