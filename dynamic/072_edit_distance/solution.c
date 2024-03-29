/**
 * Given two words word1 and word2, find the minimum number of
 * operations required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 * a. Insert a character
 * b. Delete a character
 * c. Replace a character
 * ============================================================
 *  思路
 * 1. DP状态定义: DP[i][j]表示将word1前i个字符转换为word2前j个
 *                字符所需的最少步骤。
 * 2. DP方程: if (word1[i] == word2[j]), DP[i][j] = DP[i-1][j-1]
 *            else DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1], DP[i-1][j-1])
 *                                     (DELETE)    (INSERT)     (REPLACE)
 */

int min(int x, int y, int z) {
  int ret = x < y ? x : y;
  return ret < z ? ret : z;
}

int minDistance(char *word1, char *word2) {
  int M = strlen(word1);
  int N = strlen(word2);

  int DP[M+1][N+1];

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

