/**
 * Write an efficient algorithm that searches for a value
 * in an m x n matrix. This matrix has the following properties:
 * a. Integers in each row are sorted in ascending from left to right.
 * b. Integers in each column are sorted in ascending from top to bottom.
 */

class Solution {
  public boolean searchMatrix(int[][] matrix, int target) {
    if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
      return false;
    }
    int M = matrix.length, N = matrix[0].length;
    int row = 0, col = N - 1;
    while (row < M && col >= 0) {
      if (matrix[row][col] > target) {
        col--;
      } else if (matrix[row][col] < target) {
        row++;
      } else return true;
    }
    return false;
  }
}
