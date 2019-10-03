class Solution {
  private int N, grid[][], visited[];

  public void dfs(int i) {
    visited[i] = 1;
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 1 && visited[j] == 0) {
        dfs(j);
      }
    }
  }

  public int findCircleNum(int[][] data) {
    grid = data;
    N = grid.length;
    if (N == 0) return 0;
    visited = new int[N];
    int cnt = 0;

    for (int i = 0; i < N; i++) {
      if (visited[i] == 0) {
        dfs(i);
        cnt++;
      }
    }

    return cnt;
  }

  public static void main(String args[]) {
    int grid[][] = {
      {1,0,0,1},
      {0,1,1,0},
      {0,1,1,1},
      {1,0,1,1}
    };

    assert new Solution().findCircleNum(grid) == 1;
    System.out.println("ALL TESTS PASSED!");
  } 
}

