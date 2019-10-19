/**
 * Design and implement a data structure for Least
 * Recently Used (LRU) cache. It should support the
 * following operations: get and put.
 * get(key) - Get the value (will always be positive)
 * of the key if the key exists in the cache, otherwise
 * return -1.
 * put(key, value) - Set or insert the value if the key
 * is not already present. When the cache reached its
 * capacity, it should invalidate the least recently used
 * item before inserting a new item.
 * The cache is initialized with a positive capacity.
 */

class LRUCache {
  private class Node{
    private int key;
    private int value;
    private Node pre;
    private Node next;
    public Node() {}
    public Node(int key, int value){
      this.key = key;
      this.value = value;
    }
  }

  private Node dummyHead = new Node();
  private Node dummyTail = new Node();
  private int capacity;
  private int size;
  private HashMap<Integer, Node> hashMap = new HashMap<>();

  private void add(Node node){
    Node originHead = dummyHead.next;
    dummyHead.next = node;
    node.pre = dummyHead;
    node.next = originHead;
    originHead.pre = node;
  }

  private void del(Node node){
    Node preNode = node.pre;
    Node nextNode = node.next;
    preNode.next = nextNode;
    nextNode.pre = preNode;
    node.pre = null;
    node.next = null;
  }

  public LRUCache(int capacity) {
    dummyHead.next = dummyTail;
    dummyTail.pre = dummyHead;
    this.capacity = capacity;
    size = 0;
  }

  public int get(int key) {
    Node node = hashMap.get(key);
    if(null == node){
      return -1;
    }
    del(node);
    add(node);
    return node.value;
  }

  public void put(int key, int value) {
    Node node = hashMap.get(key);

    if(node != null){
      node.value = value;
      del(node);
      add(node);
    } else {
      if(size < capacity){
        size++;
      } else {
        Node delNode = dummyTail.pre;
        hashMap.remove(delNode.key);
        del(delNode);
      }

      Node newNode = new Node(key, value);
      add(newNode);
      hashMap.put(key, newNode);
    }
  }
}

