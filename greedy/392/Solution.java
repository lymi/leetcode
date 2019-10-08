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


