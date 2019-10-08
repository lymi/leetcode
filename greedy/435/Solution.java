class Solution {
	public int eraseOverlapIntervals(int[][] intervals) {
		int N = intervals.length;
		if (N <= 1) return 0;
		Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
		int tail = intervals[0][1], cnt = 0;

		for (int i = 1; i < N; i++) {
			if (intervals[i][0] < tail) {
				cnt++;
				if (intervals[i][1] < tail) {
					tail = intervals[i][1];
				}
			} else {
				tail = intervals[i][1];
			}
		}
		return cnt;
	}
}

