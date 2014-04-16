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

void fixprev(node *root){
    static node *prev=NULL;
    if(root!=NULL){
        fixprev(root->left);
        root->left=prev;
        prev=root;
        fixprev(root->right);
    }
}

node * fixnext(node *root){
    node *prev=NULL;
    while(root && root->right){
        root=root->right;
    }
    while(root && root->left){
        prev=root;
        root=root->left;
        root->right=prev;
    }
    return root;
}

node * convert3(node *root){
    if(root==NULL)return NULL;
    fixprev(root);
    return fixnext(root);
}