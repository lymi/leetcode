#include <assert.h>
#include <stdio.h>

/**
 * 思路同P188，只需将 K 替换成2。
 */

int max(int x, int y, int z) {
  int ret = x > y ? x : y;
  return ret > z ? ret : z;
}

int maxProfit(int *prices, int N) {
  if (N <= 0) return 0;

  int ret = 0;

  if (N <= 4) {
    for (int i = 1; i < N; i++) {
      if (prices[i] > prices[i-1]) {
        ret += prices[i] - prices[i-1];
      }
    }

    return ret;
  }

  int DP[3][N+1];

  for (int k = 0; k <= 2; k++) {
    for (int i = 0; i < N; i++) {
      DP[k][i] = 0;
    }
  }
 
  for (int k = 1; k <= 2; k++) {
    int localMax = -prices[0];

    for (int i = 1; i < N; i++) {
      if (DP[k-1][i-1] - prices[i-1] > localMax) {
        localMax = DP[k-1][i-1] - prices[i-1]; 
      }

      DP[k][i] = max(DP[k-1][i], DP[k][i-1], prices[i] + localMax);
    }
  }

  return DP[2][N-1];
}

int main() {
  int arr1[8] = {3,3,5,0,0,3,1,4};
  assert(maxProfit(arr1, 8) == 6);

  int arr2[5] = {1,2,3,4,5};
  assert(maxProfit(arr2, 5) == 4);

  int arr3[5] = {7,6,4,3,1};
  assert(maxProfit(arr3, 5) == 0);
  
  printf("ALL TESTS PASSED!\n");
  return 0;
}

