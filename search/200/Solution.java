class Solution {
  /**
   * 遍历二维数组，每次遇到'1'计数器加1，并通过DFS
   * 将'1'及与它相邻的所有'1'设为0
   */
  private char grid[][];
  private int M, N;

  public void dfs(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i+1,j);
  }

  public int numIslands(char[][] grid) {
    this.grid = grid;
    M = grid.length;
    if (M == 0) return 0;
    N = grid[0].length;
    int cnt = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == '1') {
          cnt ++;
          dfs(i, j);
        }
      }
    }
    return cnt;
  }

  public static void main(String args[]) {
    char grid[][] = {
      {'1','1','0','0','0'},
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}
    };
    assert new Solution().numIslands(grid) == 3;
    System.out.println("ALL TESTS PASSED!");
  }
}

