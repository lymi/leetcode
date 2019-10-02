#include <stdio.h>
#include <assert.h>

/**
 * 1. DP[i]: 在选中元素i的情况下，0 -> i中包含等差序列的个数
 * 2. 如果 i, i-1, i-2 构成等差数列, DP[i] = DP[i-1] + 1
 *    否则 DP[i] = 0
 * 3. 结果为 SUM{DP[i]}, i: 0 -> N-1
 */
int numberOfArithmeticSlices(int *arr, int N){
  if (N <= 2) return 0;
  int DP[N], sum = 0;
  DP[0] = 0;
  DP[1] = 0;

  for (int i = 2; i < N; i++) {
    if (arr[i]+arr[i-2] == 2 * arr[i-1]) {
      DP[i] = DP[i-1] + 1;
    } else {
      DP[i] = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    sum += DP[i];
  }

  return sum;
}

int main() {
  int arr1[4] = {1,2,3,4};
  int arr2[6] = {1,2,3,8,9,10};
  assert(numberOfArithmeticSlices(arr1, 4) == 3);
  assert(numberOfArithmeticSlices(arr2, 6) == 2);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

