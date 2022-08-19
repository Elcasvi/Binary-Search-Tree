#ifndef BST_H
#define BST_H
#include "TreeNode.h"
class BST
{
public:
  TreeNode *root;

  BST();
  bool isEmpty();
  void insertNode(TreeNode* new_node);

  void print2D(TreeNode* r,int space);
  void printPreorder(TreeNode* r);
  void printInorder(TreeNode* r);
  void printPostorder(TreeNode* r);

  TreeNode* iterativeSearch(int val);
  int height(TreeNode* r);
  void printGivenLevel(TreeNode* r,int level);
  void printLevelOrderBFS(TreeNode* r);
  TreeNode* minvalueNode(TreeNode* node);
  TreeNode* deleteNode(TreeNode* r,int v);
  bool ancestors(TreeNode *r, int);
};
#endif // BST_
