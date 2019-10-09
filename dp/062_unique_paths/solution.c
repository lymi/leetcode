/**
 * A robot is located at the top-left corner of a m x n 
 * grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the 
 * grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * ================================================
 * 思路
 * 1. DP状态定义: DP[i][j] 代表移动到点(i,j)一共有多少种不重复的走法。
 * 2. DP递推方程：DP[i][j] = DP[i-1][j] + DP[i][j-1]
 */

int uniquePaths(int m, int n){
  int DP[m][n];

  for (int i = 0; i < m; i++) {
    DP[i][0] = 1;
  }

  for (int j = 0; j < n; j++) {
    DP[0][j] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      DP[i][j] = DP[i-1][j] + DP[i][j-1];
    }
  }

  return DP[m-1][n-1];
}

