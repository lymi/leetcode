/**
 * Find the max number of strings in the string array that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * ==============================================================
 * 思路
 * 1. DP状态定义:
 *    DP[i][m][n] 代表在下标 0->i 的字符串中, 满足'0'的总数不超过m, '1'的
 *    总数不超过n, 最多有多少个字符串.
 * 2. DP转移方程:
 *    DP[i][m][n] = max(DP[i-1][m][n], DP[i-1][m-count('0')][n-count('1')] + 1)
 *    空间优化:
 *    DP[m][n] = max(DP[m][n], 1 + DP[m-count('0')][n-count('1')])
 */

int count(char *str, char c) {
  int cnt = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == c) cnt++;
  }
  return cnt;
}

int max(int x, int y) {
  return x > y ? x : y;
}

int findMaxForm(char **strs, int S, int M, int N) {
  int DP[M+1][N+1];

  for (int m = 0; m <= M; m++) {
    for (int n = 0; n <= N; n++) {
      DP[m][n] = 0;
    }
  }

  for (int i = 0; i < S; i++) {
    int cnt0 = count(strs[i], '0');
    int cnt1 = count(strs[i], '1');
    for (int m = M; m >= cnt0; m--) {
      for (int n = N; n >= cnt1; n--) {
        DP[m][n] = max(DP[m][n], 1 + DP[m-cnt0][n-cnt1]);
      }
    }
  }

  return DP[M][N];
}

