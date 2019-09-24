#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * 1. DP状态定义:
 *    DP[i][m][n] 表示前i+1个字符串中, 满足'0'的总数不超过m, '1'的
 *    总数不超过n, 最多有多少个字符串.
 * 2. DP转移方程:
 *    DP[i][m][n] = max(DP[i-1][m][n], DP[i-1][m-count(strs[i],'0')][n-count(strs[i],'1')] + 1)
 */
int count(char *str, char c) {
  int cnt = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == c) {
      cnt++;
    }
  }
  return cnt;
}

int max(int x, int y) {
  return x > y ? x : y;
}

int findMaxForm(char **strs, int S, int M, int N) {
  int DP[S][M+1][N+1];

  for (int m = 0; m <= M; m++) {
    for (int n = 0; n <= N; n++) {
      if (count(strs[0], '0') <= M && count(strs[0], '1') <= N) {
        DP[0][m][n] = 1;
      } else {
        DP[0][m][n] = 0;
      }
    }
  }

  DP[0][0][0] = 0;

  for (int i = 1; i < S; i++) {
    for (int m = 0; m <= M; m++) {
      for (int n = 0; n <= N; n++) {
        int prevcnt0 = m - count(strs[i], '0');
        int prevcnt1 = n - count(strs[i], '1');

        if (prevcnt0 >= 0 && prevcnt1 >= 0) {
          DP[i][m][n] = max(DP[i-1][m][n], DP[i-1][prevcnt0][prevcnt1] + 1);
        } else {
          DP[i][m][n] = DP[i-1][m][n];
        }
      }
    }
  }

  return DP[S-1][M][N];
}

int main() {
  char *strs1[5] = {"10", "0001", "111001", "1", "0"};
  assert(findMaxForm(strs1, 5, 5, 3) == 4);
  char *strs2[3] = {"10", "0", "1"};
  assert(findMaxForm(strs2, 3, 1, 1) == 2);
  
  printf("ALL TESTS PASSED!\n");
  return 0;
}

