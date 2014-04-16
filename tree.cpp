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
    if(root==NULL)return NULL;
    if(root->left!=NULL){
        node left = convert2(root->left);
        while(;left->right!=NULL;left=left->right);
        left->right=root;
        root->left=left;
    }
    if(root->right!=NULL){
        node right = convert2(root->right);
        while(;right->left!=NULL;right=right->left);
        right->left=root;
        root->right=right;
    }
    return root;
}
