/**
 *
 * Given a n x n matrix where each of the rows and columns 
 * are sorted in ascending order, find the kth smallest 
 * element in the matrix.
 * Note that it is the kth smallest element in the sorted 
 * order, not the kth distinct element.
 */

class Solution {
  public int kthSmallest(int[][] matrix, int k) {
    int M = matrix.length, N = matrix[0].length;
    int low = matrix[0][0], high = matrix[M-1][N-1], mid, cnt;

    while (low <= high) {
      mid = low + (high - low) / 2;
      cnt = 0;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (matrix[i][j] <= mid) {
            cnt++;
          }
        }
      }
      if (cnt < k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
}

