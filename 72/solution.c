#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * 1. DP状态定义: DP[i][j]表示将word1前i个字符转换为word2前j个
 *                字符所需的最少步骤。
 * 2. DP方程: if (word1[i] == word2[j]), DP[i][j] = DP[i-1][j-1]
 *            else DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1], DP[i-1][j-1])
 */

int min(int x, int y, int z) {
  int r = x;
  if (y < r) r = y;
  if (z < r) r = z;

  return r;
}

int minDistance(char *word1, char *word2) {
  int M = strlen(word1);
  int N = strlen(word2);

  int DP[M+5][N+5];

  for (int i = 0; i <= M; i++) {
    DP[i][0] = i;
  }

  for (int j = 0; j <= N; j++) {
    DP[0][j] = j;
  }

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      if (word1[i-1] == word2[j-1]) {
        DP[i][j] = DP[i-1][j-1];
      } else {
        DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1], DP[i-1][j-1]); 
      }
    }
  }

  return DP[M][N];
}

int main() {
  assert(minDistance("horse", "ros") == 3);
  assert(minDistance("intention", "execution") == 5);
  assert(minDistance("", "") == 0);
  assert(minDistance("a", "ab") == 1);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

