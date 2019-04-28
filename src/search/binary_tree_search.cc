//
// Copyright [2019] <Zhi Sun>
//

#include "search.h"

bool binary_tree_search(Node *root, int val) {
  if (root == nullptr) {
    return false;
  }
  if (root->val == val) {
    return true;
  } else if (val < root->val) {
    return binary_tree_search(root->left, val);
  } else {
    return binary_tree_search(root->right, val);
  }
}
