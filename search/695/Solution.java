class Solution {
  private int grid[][];
  private int seen[][];
  private int M, N;

  private int area(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N ||
        seen[i][j] == 1 || grid[i][j] == 0) {
      return 0;
    }
    seen[i][j] = 1;
    return 1 + area(i-1, j) + area(i+1, j) + area(i, j-1) + area(i, j+1);
  }

  public int maxAreaOfIsland(int[][] grid) {
    this.grid = grid;
    M = grid.length;
    N = grid[0].length;
    seen = new int[M][N];
    int ans = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        ans = Math.max(ans, area(i, j));
      }
    }

    return ans;
  }

  public static void main(String args[]) {
    int grid[][] = {
      {0,0,1,0,0,0,0,1,0,0,0,0,0},
      {0,0,0,0,0,0,0,1,1,1,0,0,0},
      {0,1,1,0,1,0,0,0,0,0,0,0,0},
      {0,1,0,0,1,1,0,0,1,0,1,0,0},
      {0,1,0,0,1,1,0,0,1,1,1,0,0},
      {0,0,0,0,0,0,0,0,0,0,1,0,0},
      {0,0,0,0,0,0,0,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    assert new Solution().maxAreaOfIsland(grid) == 6;
    System.out.println("ALL TESTS PASSED!");
  }
}

