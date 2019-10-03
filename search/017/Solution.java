import java.util.List;

class Solution {
  private static final String[] KEYS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  private int N;

  public void backtrace(String prefix, List<String> ret, String digits) {
    int len = prefix.length();
    if (len == N) {
      ret.add(prefix);
      return;
    }

    int index = digits.charAt(len + 1) - '0';
    String str = KEYS[index];

    for (char c : str.toCharArray()) {
      prefix += c;
      backtrace(prefix, ret, digits);
      prefix.substring(0, len);
    }
  }

  public List<String> letterCombinations(String digits) {
    List<String> ret = new ArrayList<>();
    N = digits.length();

    if (digits == null || N == 0) return ret;

    backtrace(new String(), ret, digits);
    return ret.toString();
  }
}

