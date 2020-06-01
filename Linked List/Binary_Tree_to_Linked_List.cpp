
// Source : GFG
//Basic Inorder Traversal
void inorder(Node *root,Node *&head,Node *&prev){
  if(!root) return;
  inorder(root->left,head,prev);
  if(prev == NULL){
    head = root;
  }else{
    prev->right = root;
    root->left = prev;
  }
  prev = root;
  inorder(root->right,head,prev);
}
//root : root of tree
//head_ref: double pointer to the head of linked list
void bTreeToDLL(Node *root,Node **head_ref){
  if(!root) return;
  Node *prev = NULL;
  Node *head = NULL;
  inorder(root,head,prev);
  *head_ref = head;
}

//Reverse Inorder Traversal

void reverse_inorder(Node *root,Node **head_ref){
  if(!root) return;
  reverse_inorder(root->right,head_ref);
  root->right = *head_ref;
  if(*head_ref)
    (*head_ref)->left = root;
  *head_ref = root;
  reverse_inorder(root->left,head_ref);
}

void bTreeToDLL(Node *root,Node **head_ref){
  if(!root) return;
  reverse_inorder(root,head_ref);
  *head_ref = head;
}
