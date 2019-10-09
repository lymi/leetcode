/**
 * Given a non-empty string s and a dictionary wordDict containing
 * a list of non-empty words, determine if s can be segmented into
 * a space-separated sequence of one or more dictionary words.
 * Note:
 * 1. The same word in the dictionary may be reused multiple times in the segmentation.
 * 2. You may assume the dictionary does not contain duplicate words.
 */

import java.util.*;

class Solution {
  private List<List<String>> ret = new ArrayList<>();
  private List<String> temp = new ArrayList<>();
  private String substr;

  private boolean isPalindrome(String s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
      if (s.charAt(i++) != s.charAt(j--)) return false;
    }
    return true;
  }

  private void backtrace(String s) {
    if (s.length() == 0) {
      ret.add(new ArrayList<>(temp));
      return;
    }

    for (int i = 0; i < s.length(); i++) {
      substr = s.substring(0, i+1);
      if (isPalindrome(substr)) {
        temp.add(substr);
        backtrace(s.substring(i+1));
        temp.remove(temp.size() - 1);
      }
    }
  }

  public List<List<String>> partition(String s) {
    backtrace(s);
    return ret;
  }
}

