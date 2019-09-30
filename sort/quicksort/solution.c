#include <stdio.h>
#include <assert.h>

int partition(int *nums, int low, int high) {
  int i = low, j = high, v = nums[low];
  while(i < j) {
    while(i < j && nums[j] >= v) { j--; }
    nums[i] = nums[j];
    while(i < j && nums[i] <= v) { i++; }
    nums[j] = nums[i];
  }
  nums[i] = v;

  return i;
}

void sort(int *nums, int low, int high) {
  if (low >= high) return;
  int pivot = partition(nums, low, high);
  sort(nums, 0, pivot-1);
  sort(nums, pivot+1, high);
}

void quicksort(int *nums, int N) {
  sort(nums, 0, N-1);
}

int main() {
  int nums[10] = {2,4,3,1,7,6,9,0,5,2};
  quicksort(nums, 10);
  for (int i = 0; i < 10; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}

