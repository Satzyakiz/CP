

// Input:
// 3
// 5
// 10 30 20 5 15
// N N L L L
// 4
// 1 2 4 3
// N N L L
// 6
// 1 2 4 6 5 3
// N N N L L L
//
// Output:
// 20 30 5 10 15
// 4 2 3 1
// 6 4 5 2 3 1



struct Node *newNode(int val){
    struct Node *temp = new struct Node(val);
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *helper(int pre[],char preLN[],int *currIndex,int n){
    int index = *currIndex;
    if(index == n)
        return NULL;

    struct Node *temp = newNode(pre[index]);
    (*currIndex)++;
    if(preLN[index] == 'N'){
        temp->left = helper(pre,preLN,currIndex,n);
        temp->right = helper(pre,preLN,currIndex,n);
    }
    return temp;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int currIndex = 0;
    return helper(pre,preLN,&currIndex,n);
}
