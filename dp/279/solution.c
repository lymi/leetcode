#include <stdio.h>
#include <assert.h>
#include <math.h>

/**
 *
 * 1. DP[i] 表示数字i能分解几个数平方和需要的最少数字个数。
 * 2. DP[i] =  min{ DP[j] + DP[i-j] }
 */
int numSquares(int n) {
  int MAX = n + 1;
  int DP[n+1], min;

  for (int i = 0; i <= n; i++) {
    DP[i] = MAX;
  }

  for (int i = 1; i <= sqrt(n); i++) {
    DP[i * i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    min = MAX;
    if (DP[i] == 1) continue;
    for (int j = 1; j <= i; j++) {
      if (min > DP[j] + DP[i-j]) {
        min = DP[j] + DP[i-j];
      }
    }
    DP[i] = min;
  }

  return DP[n];
}

int main() {
  assert(numSquares(12) == 3);
  assert(numSquares(13) == 2);
  
  printf("ALL TESTS PASSED!\n");
  return 0;
}

