#include <stdio.h>
#include <assert.h>

/**
 * 1. DP[i] 代表i分解后乘积的最大值
 * 2. DP[i] = max{ max(j * DP[i-j], j * (i-j)) }   (j: 1 -> i)
 */

int max(int x, int y) {
  return x > y ? x : y;
}

int integerBreak(int n) {
  int DP[n+1], maximum, temp;
  DP[0] = 0;

  for (int i = 1; i <= n; i++) {
    maximum = 0;
    for (int j = 1; j < i; j++) {
      temp = max(j * DP[i-j], j * (i-j));
      if (maximum < temp) {
        maximum = temp;
      }
    }

    DP[i] = maximum;
  }

  return DP[n];
}

int main() {
  assert(integerBreak(2) == 1);
  assert(integerBreak(10) == 36);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

