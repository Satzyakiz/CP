// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"


    string serialize(TreeNode* root) {
        if(!root)
            return "N";
        string s = to_string(root->val);
        string left = ","+serialize(root->left);
        string right = ","+serialize(root->right);
        return s+left+right;
    }

    // Decodes your encoded data to tree.
    TreeNode *DShelper(string data,int &index){
        if(index >= data.size())
            return NULL;
        if(data[index] == 'N'){
            index += 2;
            return NULL;
        }
        string s = "";
        while(index < data.size() && data[index] != ','){
            s += data[index];
            index++;
        }
        index++;
        if(s == "")
            return NULL;
        int x = stoi(s);
        TreeNode *root = new TreeNode(x);
        root->left = DShelper(data,index);
        root->right = DShelper(data,index);
        return root;
    }
    TreeNode* deserialize(string s) {
        int index = 0;
        return DShelper(s,index);
    }

//GFG version:
void Shelper(Node *root,vector<int> &A){
    if(root == NULL){
        A.emplace_back(3333);
        return;
    }
    A.emplace_back(root->data);
    Shelper(root->left,A);
    Shelper(root->right,A);
}
void serialize(Node *root,vector<int> &A)
{
    A.clear();
    Shelper(root,A);
}

/*this function deserializes
 the serialized vector A*/
 Node *DShelper(vector<int> &A,int &index){
     if(index >= A.size())
        return NULL;
    if(A[index] == 3333){
        index++;
        return NULL;
    }
    Node *temp = new Node(A[index]);
    index++;
    temp->left = DShelper(A,index);
    temp->right = DShelper(A,index);
    return temp;
 }
Node * deSerialize(vector<int> &A)
{
   //Your code here
   int index = 0;
   return DShelper(A,index);
}
