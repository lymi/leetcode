/**
 *
 * Given a string s and a string t, check if s is subsequence of t.
 * A subsequence of a string is a new string which is formed from the
 * original string by deleting some (can be none) of the characters
 * without disturbing the relative positions of the remaining characters.
 * (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 */

class Solution {
	public boolean isSubsequence(String s, String t) {
		int M = s.length(), N = t.length(), i = 0, j = 0;
		boolean flag;
		char source[] = s.toCharArray();
		char target[] = t.toCharArray();

		while (i < M) {
			flag = false;
			while(j < N) {
				if (target[j++] == source[i]) {
					flag = true;
					break;
				}
			}
			if (!flag) return false;
			i++;
		}
		return true;
	}
}


