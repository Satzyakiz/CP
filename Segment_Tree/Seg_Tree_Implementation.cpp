#include<bits/stdc++.h>
using namespace std;

void buildTree(int *tree,int *a,int index,int s,int e){
  //Base case
  if(s > e)
    return;
  //Base case -Leaf Node
  if(s == e){
    tree[index] = a[s];
    return;
  }
  //Recursive case
  int mid = s + (e-s)/2;
  //Build Left Subtree
  buildTree(tree,a,2*index,s,mid);
  //Build Right Subtree
  buildTree(tree,a,2*index+1,mid+1,e);
  int left = tree[2*index];
  int right = tree[2*index+1];
  tree[index] = min(left,right);
}

//Query
int query(int *tree,int index,int s,int e,int qs,int qe){
  // 3 cases - No overlap, partial overlap, complete overlap
  //No overlap
  if(qs > e || qe < s){
    return INT_MAX; // Same as infinity
  }
  //Complete overlap
  if(s >= qs && e <= qe){
    return tree[index];
  }
  //partial overlap
  int mid = (s+e)/2;
  int leftAns = query(tree,2*index,s,mid,qs,qe);
  int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);

  return min(leftAns,rightAns);
}

//Node Update
void updateNode(int *tree,int index,int s,int e,int i,int value){
  //No overlap
  if(i < s || i > e)
    return;
  //Reached leaf node
  if(s == e){
    tree[index] = value;
    return;
  }
  //Partial Overlap
  //Lying in range, i.e. i in between s and e
  int mid = (s+e)/2;
  updateNode(tree,2*index,s,mid,i,value);
  updateNode(tree,2*index+1,mid+1,e,i,value);
  tree[index] = min(tree[2*index],tree[2*index+1]);
  return;
}

//Range update
//You will be given a range between rs and rv
//Increment every value in the range by v
void updateRange(int *tree,int index,int s,int e,int rs,int re,int value){
  //No overlap
  if(re < s || rs > e)
    return;
  //Reached leaf node
  if(s == e){
    tree[index] += value;
    return;
  }
  //Partial Overlap
  int mid = (s+e)/2;
  updateRange(tree,2*index,s,mid,rs,re,value);
  updateRange(tree,2*index+1,mid+1,e,rs,re,value);
  tree[index] = min(tree[2*index],tree[2*index+1]);
  return;
}

int main(){
  int arr[] = {1,3,2,-2,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  //Build the tree array
  int *tree = new int[4*n + 1];
  int index = 1; //starting from index 1
  int start = 0,end = n-1;
  buildTree(tree,arr,index,0,n-1);
  cout<<endl;
  cout<<"Query in range 1 to 6 : ";
  cout<<query(tree,index,start,end,0,6)<<endl;
  cout<<endl;
  cout<<"Query in range 1 to 3 : ";
  cout<<query(tree,index,start,end,0,3)<<endl;
  cout<<endl;
  cout<<"Query in range 4 to 6 : ";
  cout<<query(tree,index,start,end,3,5)<<endl;
  updateNode(tree,index,start,end,5,-10);
  cout<<"After update: "<<endl;
  cout<<"Query in range 1 to 6 : ";
  cout<<query(tree,index,start,end,0,6)<<endl;
  cout<<endl;
  cout<<"Query in range 1 to 3 : ";
  cout<<query(tree,index,start,end,0,3)<<endl;
  cout<<endl;
  updateRange(tree,index,start,end,5,5,-50);
  cout<<"After range update: "<<endl;
  cout<<"Query in range 1 to 6 : ";
  cout<<query(tree,index,start,end,0,6)<<endl;
  cout<<endl;
  cout<<"Query in range 1 to 3 : ";
  cout<<query(tree,index,start,end,0,3)<<endl;
  cout<<endl;
  return 0;
}

// O/P:
// Query in range 1 to 6 : -2
//
// Query in range 1 to 3 : -2
//
// Query in range 4 to 6 : -2
// After update
// Query in range 1 to 6 : -10
//
// Query in range 1 to 3 : -2
// After range update:
// Query in range 1 to 6 : -60
//
// Query in range 1 to 3 : -2
