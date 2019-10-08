class Solution {
	public int findMinArrowShots(int[][] points) {
		int N = points.length;
		if (N == 0) return 0;
		Arrays.sort(points, (a, b) -> a[0] - b[0]);

		int end = points[0][1], cnt = 1;

		for (int i = 1; i < N; i++) {
			if (points[i][0] > end) {
				cnt++;
				end = points[i][1];
			} else if (end > points[i][1]) {
				end = points[i][1];
			}
		}

		return cnt;
	}
}
