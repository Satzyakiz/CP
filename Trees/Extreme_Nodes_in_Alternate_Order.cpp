// Input:
// 1
// 1 2 3
//
// Output:
// 1 2

void printExtremeNodes(Node* root)
{
    // Your code here
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        int k = q.size();
        int count =  0;
        while(count < k){
            Node *temp = q.front();
            q.pop();
            if(flag == true && count == 0){
                cout<<temp->data<<" ";
            }
            if(flag == false && count == k-1){
                cout<<temp->data<<" ";
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            count++;
        }
        flag = flag == false ? true : false;
    }
}
