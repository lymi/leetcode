class Solution {
  /**
   * 1. DP[i][j]: 走到(i,j)点时经过路径上所有数之和的最小值
   * 2. DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j]
   */
  public int minPathSum(int[][] grid) {
    int M = grid.length;
    if (M == 0) return 0;
    int N = grid[0].length;
    int DP[][] = new int[M][N];

    DP[0][0] = grid[0][0];

    for (int i = 1; i < M; i++) {
      DP[i][0] = DP[i-1][0] + grid[i][0];
    }

    for (int j = 1; j < N; j++) {
      DP[0][j] = DP[0][j-1] + grid[0][j];
    }

    for (int i = 1; i < M; i++) {
      for (int j = 1; j < N; j++) {
        DP[i][j] = grid[i][j] + Math.min(DP[i-1][j], DP[i][j-1]);
      }
    }
    
    return DP[M-1][N-1];
  }

  public static void main(String args[]) {
    int grid[][] = {{1,3,1},{1,5,1},{4,2,1}};
    Solution so = new Solution();
    System.out.println(so.minPathSum(grid));
  }
}

