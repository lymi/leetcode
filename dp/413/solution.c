#include <stdio.h>
#include <assert.h>

/**
 * 1. DP[i]: 序列0 -> i中所包含等差数列的个数
 * 2. if arr[i] + arr[i-2] == 2 * arr[i-1], DP[i] = DP[i-1] + 1
 *    else DP[i] = DP[i-1]
 */
int numberOfArithmeticSlices(int *arr, int N){
  int DP[N], sum = 0;
  DP[0] = 0;
  DP[1] = 0;

  for (int i = 2; i < N; i++) {
    if (arr[i]+arr[i-2] == 2 * arr[i-1]) {
      DP[i] = DP[i-1] + 1;
    } else {
      DP[i] = DP[i-1];
    }
  }

  for (int i = 0; i < N; i++) {
    sum += DP[i];
  }

  return sum;
}

int main() {
  int arr[4] = {1,2,3,4};
  assert(numberOfArithmeticSlices(arr, 4) == 3);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

