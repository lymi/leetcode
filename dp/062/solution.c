#include <stdio.h>
#include <assert.h>

/**
 * 1. DP[i][j]: 移动到点(i,j)一共有多少种不重复的走法。
 * 2. DP[i][j] = DP[i-1][j] + DP[i][j-1]
 */

int uniquePaths(int m, int n){
  int DP[m][n];

  DP[0][0] = 0;
  for (int i = 1; i < m; i++) {
    DP[i][0] = 1;
  }

  for (int j = 1; j < n; j++) {
    DP[0][j] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      DP[i][j] = DP[i-1][j] + DP[i][j-1];
    }
  }

  return DP[m-1][n-1];
}

int main() {
 assert(uniquePaths(3,2) == 3); 
 printf("ALL TESTS PASSED!\n");
}
