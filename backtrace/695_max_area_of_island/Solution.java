/**
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of
 * 1's (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no 
 * island, the maximum area is 0.)
 */

class Solution {
  private int grid[][];
  private int visited[][];
  private int M, N;

  private int area(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N ||
        visited[i][j] == 1 || grid[i][j] == 0) {
      return 0;
    }
    visited[i][j] = 1;
    return 1 + area(i-1, j) + area(i+1, j) + area(i, j-1) + area(i, j+1);
  }

  public int maxAreaOfIsland(int[][] grid) {
    this.grid = grid;
    M = grid.length;
    N = grid[0].length;
    visited = new int[M][N];
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

