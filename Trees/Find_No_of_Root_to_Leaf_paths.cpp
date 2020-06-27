// Given a binary tree, you need to find the number of all root to leaf
// paths along with their path lengths.
// Input:
// 2
// 2
// 3 2 L 3 4 R
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R
// Output:
// 2 2 $
// 2 1 $3 2 $
//
// Explanation :
// Testcase1:
// There are 2 root to leaf paths of length 2.
//
// Testcase2:
// There is 1 root to leaf paths of length 2 and 2 root to leaf
// paths of length 3.

void help(Node*root,map<int,int> &m,int d)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        m[d]++;
    }
    help(root->left,m,d+1);
    help(root->right,m,d+1);
}
void pathCounts(Node *root)
{
    map<int,int> m;
    help(root,m,1);
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" "<<i->second<<" $";
    }
}
