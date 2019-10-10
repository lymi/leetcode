class MergeSort {
  private void merge(int[] nums, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[] = new int[high-low+1];

    while (i <= mid && j <= high) {
      if (nums[i] < nums[j]) {
        temp[k++] = nums[i++];
      } else {
        temp[k++] = nums[j++];
      }
    }
    while (i <= mid) { temp[k++] = nums[i++]; }
    while (j <= high) { temp[k++] = nums[j++]; }

    for (int m = 0; m < temp.length; m++) {
      nums[low + m] = temp[m]; 
    }
  }

  private void mergesort(int[] nums, int low, int high) {
    if (low == high) return;
    int mid = low + (high - low) / 2;
    mergesort(nums, low, mid);
    mergesort(nums, mid+1, high);
    merge(nums, low, mid, high);
  }

  public void sort(int[] nums) {
    mergesort(nums, 0, nums.length - 1);
  }

  public static void main(String args[]) {
     int[] nums = {2,4,3,1,7,6,9,0,5,2};
     new MergeSort().sort(nums);
     for (int i = 0; i < nums.length; i++) {
       System.out.print(nums[i] + " ");
     }
  }
}

