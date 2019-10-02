#include <stdio.h>
#include <assert.h>
#include <math.h>

/**
 * 1. DP[i]: 将数字 i 能分解平方和需要的最少数字个数。
 * 2. DP[i] = min{ DP[i-j*j] } + 1
 *                (0 <= j <= sqrt(i))
 */

int numSquares(int n) {
  int MAX = n + 1;
  int DP[n+1], temp;

  DP[0] = 0;

  for (int i = 1; i < MAX; i++) {
    DP[i] = MAX;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sqrt(i); j++) {
      temp = DP[i-j*j] + 1;
      if (DP[i] > temp) {
        DP[i] = temp;
      }
    }
  }

  return DP[n];
}

int main() {
  assert(numSquares(12) == 3);
  assert(numSquares(13) == 2);
  
  printf("ALL TESTS PASSED!\n");
  return 0;
}

