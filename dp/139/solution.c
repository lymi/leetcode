#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * 1. DP状态定义:
 *    DP[i] 代表目标字符串的前 i 个字符构成的子串是否可分割。
 * 2. DP转移方程:
 *    DP[i] = Whichever is true {DP[i-len] && strcmp(s[i-len], word)}
 *                                 (0 <= j < N)
 */

int strcmp2(const char *s1, const char *s2, int len) {
  int ret = 0;
  for (int i = 0; i < len; i++) {
    if (*(s1+i) != *(s2+i)) {
      ret = -1;
      break;
    }
  }
  return ret;
}

int wordBreak(char *s, char **wordDict, int N) {
  int SIZE = strlen(s), len;
  int DP[SIZE+1];

  DP[0] = 1;
  for (int i = 1; i <= SIZE; i++) {
    DP[i] = 0;
  }

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 0; j < N; j++) {
      len = strlen(wordDict[j]);
      if (i >= len && strcmp2(&s[i-len], wordDict[j], len) == 0 && DP[i-len] == 1) {
        DP[i] = 1;
      }
    }
  }
  
  return DP[SIZE];
}

int main() {
  char *words1[2] = {"leet", "code"};
  char *words2[2] = {"apple", "pen"};
  char *words3[5] = {"cats", "dog", "sand", "and", "cat"};

  assert(wordBreak("leetcode", words1, 2) == 1);
  assert(wordBreak("applepenapple", words2, 2) == 1);
  assert(wordBreak("catsandog", words3, 5) == 0);

  printf("ALL TESTS PASSED!\n");
  return 0;
}

