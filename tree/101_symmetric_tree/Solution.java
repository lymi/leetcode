/**
 * 判断二叉树是否对称
 */

class Solution {
  private boolean judge(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return true;
    if (t1 == null || t2 == null) return false;
    if (t1.val != t2.val) return false;
    return judge(t1.left, t2.right) && judge(t1.right, t2.left);
  }

  public boolean isSymmetric(TreeNode root) {
    if (root == null) return true;
    return judge(root.left, root.right);
  }
}
