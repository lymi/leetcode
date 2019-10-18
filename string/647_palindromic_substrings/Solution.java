/**
 * Given a string, your task is to count how many
 * palindromic substrings in this string.
 * The substrings with different start indexes or
 * end indexes are counted as different substrings
 * even they consist of same characters.
 */

class Solution {
  public int countSubstrings(String s) {
    int cnt = 0, N = 2 * s.length() - 1;
    int left, right;
    char[] chars = s.toCharArray();

    for (int i = 0; i < N; i++) {
      left = i / 2;
      right = i % 2 == 0 ? left : left + 1;

      while (left >= 0 && right < s.length() && chars[left] == chars[right]) {
        cnt++;
        left--;
        right++;
      }
    }
    return cnt;
  }
}

