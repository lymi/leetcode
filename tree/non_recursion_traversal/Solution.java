/**
 * 二叉树前中后序遍历的非递归实现
 */

class Solution {
  // 前序遍历: root -> left -> right
  public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode top;

    stack.push(root);
    while (!stack.isEmpty()) {
      top = stack.pop();
      if (top != null) {
        ret.add(top.val);
        stack.push(top.right);
        stack.push(top.left);  // 先访问左边的节点
      }
    }
    return ret;
  }

  // 中序遍历: left -> root -> right
  public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode top;

    TreeNode curr = root;
    while(!stack.isEmpty() || curr != null) {
      while(curr != null) {
        stack.push(curr);
        curr = curr.left;
      }
      top = stack.pop();
      ret.add(top.val);
      curr = top.right;
    }
    return ret;
  }

  // 后续遍历: left -> right -> root, 相当于将 root -> right -> left 反过来
  public List<Integer> postorderTraversal(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode top;

    stack.push(root);
    while (!stack.isEmpty()) {
      top = stack.pop();
      if (top != null) {
        ret.add(top.val);
        stack.push(top.left);
        stack.push(top.right);
      }
    }

    Collections.reverse(ret);
    return ret;
  }  
}

