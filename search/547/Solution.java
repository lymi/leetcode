class Solution {
  private int M, N, grid[][];

  public void dfs(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) {
      return;
    }
    grid[i][j] = 0;
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
  }

  public int findCircleNum(int[][] data) {
    grid = data;
    M = grid.length;
    if (M == 0) return 0;
    N = grid[0].length;
    int cnt = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == 1) {
          cnt++;
          dfs(i,j);
        }
      }
    }

    return cnt;
  }

  public static void main(String args[]) {
    int grid[][] = {
     {1,1,0},
     {1,1,0},
     {0,0,1}};
    assert new Solution().findCircleNum(grid) == 2;
    System.out.println("ALL TESTS PASSED!");
  } 
}

