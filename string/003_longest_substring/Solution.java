/**
 * Given a string, find the length of the longest
 * substring without repeating characters.
 */

class Solution {
  public int lengthOfLongestSubstring(String s) {
    char[] chars = s.toCharArray();
    int N = chars.length;
    HashSet<Character> set = new HashSet<>();
    int ans = 0, i = 0, j = 0;

    while (i < N && j < N) {
      if (set.contains(chars[j])) {
        set.remove(chars[i++]);
      } else {    
        set.add(chars[j++]);
        ans = Math.max(ans, j-i);
      }
    }
    return ans;
  }
}

