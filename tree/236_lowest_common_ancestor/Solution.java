/**
 * 求二叉树两个子节点最近的公共父节点
 */

class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || p == root || q == root) return root;
    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);

    if (left != null && right != null) return root;   // 左右子树分别找到p, q之一
    if (right != null) return right;                  // 在右子树找到p, q
    return left;                                      // 在左子树找到p, q
  }
}

