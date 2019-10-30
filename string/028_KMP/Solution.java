import java.util.*; 

class Solution {
  private int[] getNext(char[] pattern) {
    int N = pattern.length;
    // next[i]代表下标 0 -> i-1 的子串重复前后缀的最大长度
    int[] next = new int[N];
    next[0] = -1; 
    int i = 0;
    int j = -1;

    while (i < N - 1) {
      if (j == -1 || pattern[i] == pattern[j]) {
        i++;
        j++;
        next[i] = j;
      } else { 
        j = next[j];
      }
    }
    return next;
  }
  
  public int strStr(String t, String p) {
    char[] text = t.toCharArray();
    char[] pattern = p.toCharArray();
    int N1 = text.length, N2 = pattern.length;
    if (N2 == 0) return 0;
    if (N1 < N2) return -1;

    int[] next = getNext(pattern);

    int i = 0, j = 0;
    while (i < N1 && j < N2) {
      // j == -1 时意味着text[i]与pattern[0]不匹配
      // 此时i需要前进1位
      if (j == -1 || text[i] == pattern[j]) {
        i++;
        j++;
      } else {
        j = next[j];
      }
    }

    if (j == N2) return i - j;
    return -1;
  }

  public static void main(String args[]) {
    int ret = new Solution().strStr("mississipipi", "issipi");
    System.out.println(ret);
  }
}

