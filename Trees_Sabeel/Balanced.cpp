int height(Node * node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(height(node -> left), height(node -> right));
}

bool isBalanced(Node *root)
{
    // Tree balanced if lh-rh <= 1 and rightTree balanced and leftTree Balanced

    if(root == NULL) {
        return true;
    }

    int lh = height(root -> left);
    int rh = height(root -> right);

    if(abs(lh - rh) <=1 && isBalanced(root -> left) && isBalanced(root -> right)) {
        return true;
    } else {
        return false;
    }

}
