class TrieNode {
  private TrieNode[] links;
  private boolean end;

  public TrieNode() {
    this.links = new TrieNode[26];
  }

  public boolean contains(char ch) {
    return links[ch - 'a'] != null;
  }

  public void put(char ch) {
    links[ch - 'a'] = new TrieNode();
  }

  public TrieNode get(char ch) {
    return links[ch - 'a'];
  }

  public void setEnd() {
    end = true;
  }

  public boolean isEnd() {
    return end;
  }
}

class Trie {
  public TrieNode root;
  public Trie() {
    this.root = new TrieNode();
  }

  public void insert(String word) {
    TrieNode tail = root;
    for (char c : word.toCharArray()) {
      if (!tail.contains(c)) {
        tail.put(c);
      }
      tail = tail.get(c);
    }
    tail.setEnd();
  }

  private TrieNode searchPrefix(String word) {
    TrieNode tail = root;
    for (char c : word.toCharArray()) {
      if (tail.contains(c)) {
        tail = tail.get(c);
      } else {
        return null;
      }
    }
    return tail;
  }

  public boolean search(String word) {
    TrieNode tail = searchPrefix(word);
    return tail != null && tail.isEnd();
  }

  public boolean startsWith(String prefix) {
    TrieNode tail = searchPrefix(prefix);
    return tail != null;
  }
}

