// Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

struct Node* LCA(struct Node* root, int n1, int n2) {
    while(root != NULL) {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}