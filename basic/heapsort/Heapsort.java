class Heapsort {
  private int[] nums;

	private void swap(int i, int j) {
	  int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

  /**
	 * 调整以index为顶点的树，使其符合堆的特性
	 * maxIndex为数组最后一项的索引
   */
  private void maxHeapify(int index, int maxIndex) {
	  int left = index * 2 + 1;  // 左子节点
		int right = left + 1;      // 右子节点
		int max = left;            // 先默认左子节点的值最大

		if (left > maxIndex) return;
		if (rigth <= maxIndex && nums[right] > nums[left]) {
		  max = right;
		}

		if (nums[index] < nums[max]) {
		  swap[index, max];
			maxHeapify(max, len);
		}
	}

  public void sort(int[] nums) {
	  this.nums = nums;
		// Step 1: 构建堆
    int maxIndex = nums.length;
		// Step 2: 排序
	}
}

