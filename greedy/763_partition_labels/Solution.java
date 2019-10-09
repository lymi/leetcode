/**
 *
 * A string S of lowercase letters is given. We want to partition 
 * this string into as many parts as possible so that each letter
 * appears in at most one part, and return a list of integers
 * representing the size of these parts.
 */

class Solution {
	public List<Integer> partitionLabels(String S) {
		int N = S.length(), cnt = 0;
		List<Integer> ans = new ArrayList<>();
		int lastPos[] = new int[26]; // 字符c在字符串中最后出现的位置
		for (int i = 0; i < N; i++) {
			lastPos[S.charAt(i) - 'a'] = i;
		}

		int j = lastPos[S.charAt(0) - 'a'];
		for (int i = 0; i < N; i++) {
			if (lastPos[S.charAt(i) - 'a'] > j) {
				j = lastPos[S.charAt(i) - 'a'];
			}

			cnt++;

			if (i == j) {
				ans.add(cnt);
				cnt = 0;
			}
		}
		return ans;
	}
}

