
// Given two Binary Trees. Check whether they are Isomorphic or not.
// Two trees are called isomorphic if one of them can be obtained
// from other by a series of flips, i.e. by swapping left and
// right children of a number of nodes. Any number of nodes at
// any level can have their children swapped. Two empty trees are
// isomorphic.



bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL && root2 != NULL)
        return false;
    if(root1 != NULL && root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    bool same = isIsomorphic(root1->left,root2->left)
                && isIsomorphic(root1->right,root2->right);
    bool mirror = isIsomorphic(root1->right,root2->left)
                  && isIsomorphic(root1->left,root2->right);;
    if(same || mirror)
        return true;
    return false;
}
