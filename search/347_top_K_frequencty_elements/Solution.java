/**
 * Given a non-empty array of integers, return the k most frequent elements.
 */

class Solution {
  public List<Integer> topKFrequent(int[] nums, int k) {
    List<Integer> ret = new ArrayList<>();
    HashMap<Integer, Integer> map = new HashMap<>();
    for (int i : nums) {
      map.put(i, map.getOrDefault(i, 0) + 1);
    }

    // 根据元素出现的频次构造大顶堆
    PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> map.get(a) - map.get(b));

    map.forEach((key, val) -> {
      pq.add(key);
      if (pq.size() > k) {
        pq.poll();
      }
    });

    while(!pq.isEmpty()) {
      ret.add(pq.poll());
    }
    Collections.reverse(ret);
    return ret;
  }
}

