public class BiSearch {
  // 常规情况: 查找给定值在数组中的位置
	public static int bisearch0(int arr[], int target) {
		int low = 0, high = arr.length - 1, mid;

		while(low <= high) {
			mid = low + (high - low) / 2;
			if (arr[mid] > target) {
				high = mid - 1;
			} else if (arr[mid] < target) {
				low = mid + 1;
			} else {
				return mid;
			}
		}
		return -1;
	}

  // 变形1: 数组中有重复数据，查找第一个值等于给定值的元素
	//        （即给定值在数组中的最左位置）
  public static int bisearch1(int arr[], int target) {
    int low = 0, high = arr.length - 1, mid;

    while(low <= high) {
      mid = low + (high - low) / 2;
			if (arr[mid] > target) {
			  high = mid - 1;
			} else if (arr[mid] < target) {
			  low = mid + 1;
			} else {
			  if (mid == 0 || arr[mid-1] < target) return mid;
				high = mid - 1;
			}
    }

		return -1;
  }

	// 变形2: 数组中有重复数据，查找第一个大于给定值的元素
	public static int bisearch2(int arr[], target) {
	  int low = 0, high = arr.length - 1, mid;

		while (low <= high) {
		  mid = low + (high - low) / 2;
			if (arr[mid] > target) {
			  if (mid == 0 || arr[mid-1] < target) return mid;
				high = mid - 1;
			} else {
			  low = mid + 1;
			}
		}
		return -1;
	}

	// 变形3: 数组中有重复数据，查找第一个大于等于给定值的元素
	public static int bisearchr3(int arr[], int target) {
	  int low = 0, high = arr.length - 1, mid;

		while(low <= high) {
		  mid = low + (high - low) / 2;
			if (arr[mid] >= target) {
			  if (mid == 0 || arr[mid-1] < target) return mid;
				high = mid - 1;
			} else {
			  low = mid + 1;
			}
		}
		return -1;
	}
}

