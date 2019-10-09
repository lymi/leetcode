/**
 * Given a binary tree, return all root-to-leaf paths.
 * Note: A leaf is a node with no children.
 */

import java.util.*;

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int x) {
    val = x;
  }
}

class Solution {
  private List<String> ret = new ArrayList<>();

  public void backtrace(StringBuilder prefix, TreeNode node) {
    if (prefix.length() == 0) {
      prefix.append(node.val);
    } else {
      prefix.append("->" + node.val);
    }

    if (node.left == null && node.right == null) {
      ret.add(prefix.toString());
      return;
    }

    StringBuilder temp = new StringBuilder(prefix);
    if (node.left != null) {
      backtrace(prefix, node.left);
      prefix = temp;
    }

    if (node.right != null) {
      backtrace(prefix, node.right);
      prefix = temp;
    }
  }

  public List<String> binaryTreePaths(TreeNode root) {
    if (root == null) return ret;
    backtrace(new StringBuilder(), root);
    return ret;
  }

  public static void main(String args[]) {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.right = new TreeNode(5);

    List<String> list = new Solution().binaryTreePaths(root);
    for (String str : list) {
      System.out.println(str);
    }
  }
}

