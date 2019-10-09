/**
 * Given a string containing digits from 2-9 inclusive, 
 * return all possible letter combinations that the number could represent.
 */

import java.util.*;

class Solution {
  private static final String[] KEYS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  private int N;
  private String digits;
  private List<String> ret = new ArrayList<>();

  public void backtrace(StringBuilder prefix) {
    int len = prefix.length();
    if (len == N) {
      ret.add(prefix.toString());
      return;
    }
    int index = digits.charAt(len) - '0';
    String str = KEYS[index];
    for (char c : str.toCharArray()) {
      prefix.append(c);
      backtrace(prefix);
      prefix.deleteCharAt(prefix.length() - 1);
    }
  }

  public List<String> letterCombinations(String digits) {
    N = digits.length();
    if (digits == null || N == 0) return ret;
    this.digits = digits;
    backtrace(new StringBuilder());
    return ret;
  }

  public static void main(String args[]) {
    List<String> ret = new Solution().letterCombinations("23");
    for (String s : ret) {
      System.out.print(s + " ");
    }
    System.out.println();
  }
}

