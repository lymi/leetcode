#include <stdio.h>
#include <assert.h>
#include <math.h>

/**
 * 1. DP[i] 表示数字i能分解几个数平方和需要的最少数字个数。
 * 2. DP[i + j*j] =  min{ DP[i+j*j], DP[i] + 1 }
 */

int min(int x, int y) {
  return x < y ? x : y;
}

int numSquares(int n) {
  int MAX = n + 1;
  int DP[n+1];

  DP[0] = 0;
  for (int i = 1; i <= n; i++) {
    DP[i] = MAX;
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 1; i + j*j <= n; j++) {
      DP[i+j*j] = min(DP[i+j*j], DP[i]+1);
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

