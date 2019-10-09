/**
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 */

class Solution {
  private boolean visited[][];
  private int M, N;
  private String word;
  private char[][] board;

  public boolean backtrace(int index, int i, int j) {
    if (index == word.length()) return true;
    char c = word.charAt(index);

    if (i < 0 || i >= M || j < 0 || j >= N || visited[i][j] || board[i][j] != c) {
      return false;
    }

    visited[i][j] = true;
    if (backtrace(index+1, i+1, j) || backtrace(index+1, i-1, j) ||
        backtrace(index+1, i, j+1) || backtrace(index+1, i, j-1)) {
      return true;       
    }
    visited[i][j] = false;
    return false;
  }

  public boolean exist(char[][] board, String word) {
    if (board == null) return false;
    M = board.length;
    if (M == 0 || word.length() == 0) return false;
    N = board[0].length;
    visited = new boolean[M][N];
    this.board = board;
    this.word = word;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (backtrace(0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }

  public static void main(String args[]) {
    char board[][] = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };

    Solution so = new Solution();
    assert so.exist(board, "ABCCED") == true;
    assert so.exist(board, "SEE") == true;
    assert so.exist(board, "ABCB") == false;
    System.out.println("ALL TESTS PASSED!");
  }
}

