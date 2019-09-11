#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * 1. DP状态定义: DP[i][j]表示将word1[i]及之前的字符转换为word2[j]及之前
 *                字符所需的最少步骤。
 * 2. DP方程: if word1[i] == word2[j], DP[i][j] = DP[i-1][j-1]
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

  int *DP[M];

  for (int i = 0; i < M; i++) {
    DP[i] = (int *)malloc(sizeof(int) * N);
  } 

  DP[0][0] = 0;

  for (int i = 0; i < M; i++) {
    if (word1[i] == word2[0]) {
      DP[i][0] = i;
    } else {
      DP[i][0] = i + 1;
    }
  }
  
  for (int j = 0; j < N; j++) {
    if (word1[0] == word2[j]) {
      DP[0][j] = j;
    } else {
      DP[0][j] = j + 1;
    }
  }

  for (int i = 1; i < M; i++) {
    for (int j = 1; j < N; j++) {
      if (word1[i] == word2[j]) {
        DP[i][j] = DP[i-1][j-1];
      } else {
        DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1], DP[i-1][j-1]);
      }
    }
  }

  return DP[M > 0 ? M - 1 : 0][N > 0 ? N - 1 : 0];
}

int main() {
  assert(minDistance("horse", "ros") == 3);
  assert(minDistance("intention", "execution") == 5);
  assert(minDistance("", "") == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

