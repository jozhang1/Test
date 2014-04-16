struct node{
    int data;
    node* left;
    node* right;
}

void convert(node *root, node **head){
    if(root==NULL)return;
    static node *prev=NULL;
    convert(root->left,head);
    if(prev==NULL) *head=root;
    else{
        prev.right=root;
        root.left=prev;
    }
    prev=root;
    convert(root->right,head);
}

node* convert2(node *root){
    
}