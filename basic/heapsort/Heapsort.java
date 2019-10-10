class Heapsort {
  private int[] nums;

	private void swap(int i, int j) {
	  int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

  /**
	 * 调整以index为顶点的树，使其符合堆的特性
	 * last 为未排序的堆（数组）最后一项的索引
   */
  private void maxHeapify(int index, int last) {
	  int left = index * 2 + 1;  // 左子节点
		int right = left + 1;      // 右子节点
		int maxIdx = left;         // 默认左子节点的值最大

		if (left > last) return;

		if (right <= last && nums[right] > nums[left]) {
		  maxIdx = right;       
		}

		if (nums[index] < nums[maxIdx]) {
		  swap(index, maxIdx);
			maxHeapify(maxIdx, last);
		}
	}

  public void sort(int[] nums) { 
    this.nums = nums;
		// Step 1: 构建堆
    int last = nums.length - 1;
    int begin = (last - 1) / 2;   // 最后一个非叶子节点
    for (int i = begin; i >= 0; i--) {
      maxHeapify(i, last);
    }
		// Step 2: 排序
    for (int i = last; i >= 0; i--) {
      swap(0, i);
      maxHeapify(0, i-1);
    }
	}

  public static void main(String args[]) {
     int[] nums = {2,4,3,1,7,6,9,0,5,2};
     new Heapsort().sort(nums);
     for (int i = 0; i < nums.length; i++) {
       System.out.print(nums[i] + " ");
     }
  }
}

