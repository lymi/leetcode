/**
 * A sequence of number is called arithmetic if it consists of 
 * at least three elements and if the difference between any two
 * consecutive elements is the same.
 * A zero-indexed array A consisting of N numbers is given. A slice 
 * of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, 
 * this means that P + 1 < Q.
 * The function should return the number of arithmetic slices in the array A.
 * ========================================================
 * 思路
 * 1. DP[i]: 在选中元素i的情况下，0 -> i中包含等差序列的个数
 * 2. 如果 i, i-1, i-2 构成等差数列, DP[i] = DP[i-1] + 1
 *    否则 DP[i] = 0
 * 3. 结果为 SUM{DP[i]}, i: 0 -> N-1
 */
int numberOfArithmeticSlices(int *arr, int N){
  if (N <= 2) return 0;
  int DP[N], sum = 0;
  DP[0] = 0;
  DP[1] = 0;

  for (int i = 2; i < N; i++) {
    if (arr[i]+arr[i-2] == 2 * arr[i-1]) {
      DP[i] = DP[i-1] + 1;
    } else {
      DP[i] = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    sum += DP[i];
  }

  return sum;
}

