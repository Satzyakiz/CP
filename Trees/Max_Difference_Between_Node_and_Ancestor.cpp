// Input:
// 2
// 5 2 1
// 1 2 3 N N N 7
// Output:
// 4
// -1
//
// Explanation:
// Testcase 1:
//
//              5
//            /    \
//          2      1
// The maximum difference we can get is 4, which is bewteen 5 and 1.
//
// Testcase 2:
//
//              1
//            /    \
//          2      3
//                    \
//                     7
// The maximum difference we can get is -1, which is between 1 and 2.
int Traverse(Node *root, int &maxm){
  if(root == nullptr)
    return INT_MAX;
  int mini = min(Traverse(root->left, maxm), Traverse(root->right, maxm));
  maxm = max(maxm, root->data-mini);
  mini = min(mini, root->data);
  return mini;
}

int maxDiff(Node* root){
  int maxm = INT_MIN;
  Traverse(root, maxm);
  return maxm;
}
