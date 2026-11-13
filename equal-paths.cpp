#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

static bool checkLeafDepth(Node* node, int depth, int& expectedDepth) {
  if(node == nullptr) { //base case
    return true;
  }
  if(node->left == nullptr && node->right == nullptr) {
    if (expectedDepth == -1) {
      expectedDepth = depth;
    }
    return depth == expectedDepth;

  }
  return checkLeafDepth(node->left, depth + 1, expectedDepth) && checkLeafDepth(node->right, depth + 1, expectedDepth);

}


bool equalPaths(Node * root)
{
  int expectedDepth = -1;
  return checkLeafDepth(root, 0, expectedDepth);

}

