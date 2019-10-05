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

  public static void main(String args[]) {
    String s = "aab";
    List<List<String>> lists = new Solution().partition(s);
    for (List<String> list : lists) {
      for (String str : list) {
        System.out.print(str + " ");
      }
      System.out.println();
    }
  }
}

