#include <stdio.h>
#include <assert.h>

/**
 * 1. DP状态定义:
 *    DP[i]: 对于索引 0 -> i(i: 0 -> N-1) 的pairs序列, 在选中 i 的情况下,
 *    能够构成的最长链条长度。
 * 2. DP转移方程:
 *    DP[i] = max{DP[j]} + 1   (pairs[i]在链头或链尾)   (j: 0 -> i-1)
 * 3. 最终结果 max{DP[i]} (i: 0 -> N-1)
 */
int findLongestChain(int **pairs, int N, int *LENS){
  if (N <= 0) return 0;
  int DP[N], max, ret = 0;
  DP[0] = 0;

  for (int i = 0; i < N; i++) {
    max = 0;
    for (int j = 0; j < i; j++) {
      if (max < DP[j] && (pairs[i][0] > pairs[j][LENS[j]-1] ||
            pairs[i][LENS[i]-1] < pairs[j][0])) {
        max = DP[j];
      }
    }
    DP[i] = 1 + max;
  }
  
  for (int i = 0; i < N; i++) {
    if (ret < DP[i]) ret = DP[i];
  }

  return ret;
}

int main() {
  int pair1[2] = {1,2};
  int pair2[2] = {2,3};
  int pair3[2] = {3,4};
  int *pairs1[3] = {pair1, pair2, pair3};
  int *pairs2[3] = {pair3, pair2, pair1};
  int lens[3] = {2,2,2};

  assert(findLongestChain(pairs1, 3, lens) == 2);
  assert(findLongestChain(pairs2, 3, lens) == 2);

  printf("ALL TESTS PASSED!\n");
  return 0;
}
