import java.util.*;

class Solution {
  private static final String[] KEYS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  private int N;

  public void backtrace(StringBuilder prefix, List<String> ret, String digits) {
    int len = prefix.length();
    if (len == N) {
      ret.add(prefix.toString());
      return;
    }

    int index = digits.charAt(len) - '0';
    String str = KEYS[index];

    for (char c : str.toCharArray()) {
      prefix.append(c);
      backtrace(prefix, ret, digits);
      prefix.deleteCharAt(prefix.length() - 1);
    }
  }

  public List<String> letterCombinations(String digits) {
    List<String> ret = new ArrayList<>();
    N = digits.length();

    if (digits == null || N == 0) return ret;

    backtrace(new StringBuilder(), ret, digits);
    return ret;
  }

  public static void main(String args[]) {
    List<String> ret = new Solution().letterCombinations("23");
    for (String s : ret) {
      System.out.print(s + " ");
    }
  }
}

