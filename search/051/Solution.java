import java.util.*;

class Solution {
  private List<List<String>> ret;
  private char nQueens[][];
  private boolean[] colUsed;
  private boolean[] diag45Used;
  private boolean[] diag135Used;
  private int N;

  private void backtrace(int row) {
    if (row == N) {
      List<String> temp = new ArrayList<>();
      for (char[] chars: nQueens) {
        temp.add(new String(chars));
      }
      ret.add(temp);
      return;
    }

    for (int col = 0; col < N; col++) {
      int idx_45 = row + col;
      int idx_135 = N - 1 - (row - col);

      if (colUsed[col] || diag45Used[idx_45] || diag135Used[idx_135]) {
        continue;
      }

      nQueens[row][col] = 'Q';
      colUsed[col] = diag45Used[idx_45] = diag135Used[idx_135] = true;
      backtrace(row + 1);
      colUsed[col] = diag45Used[idx_45] = diag135Used[idx_135] = false;
      nQueens[row][col] = '.';
    }
  }

  public List<List<String>> solveNQueens(int n) {
    this.N = n;
    ret = new ArrayList<>();
    colUsed = new boolean[N];
    diag45Used = new boolean[2 * N - 1];
    diag135Used = new boolean[2 * N - 1];
    nQueens = new char[N][N];

    for (int i = 0; i < N; i++) {
      Arrays.fill(nQueens[i], '.');
    }

    backtrace(0);
    return ret;
  }

  public static void main(String args[]) {
    List<List<String>> lists = new Solution().solveNQueens(4);
    for (List<String> list : lists) {
      for (String s : list) {
        System.out.println(s);
      }
      System.out.println();
    }
  }
}

