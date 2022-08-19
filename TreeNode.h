#ifndef TREENODE_H
#define TREENODE_H
#include <string>
class TreeNode
{
  public:
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode();
  TreeNode(int v);

  friend class BST;
};
#endif // TREENODE_H
