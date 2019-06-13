int isBSTUtil(Node * root, int min, int max) {
    if(root == NULL) {
        return 1;
    }

    // root's data should be between min and max else false
    if(root -> data < min || root -> data > max) {
        return 0;
    }

    // now check if left subtree and right subtree are bst's
    // for left, allowed range is INT_MIN to root - > data - 1
    // for right, allowed range is root -> data + 1 to INT_MAX
    return isBSTUtil(root -> left, min, root -> data - 1) &&
           isBSTUtil(root -> right, root -> data + 1, max);
}

bool isBST(Node* root) {
    // max in left subtree should be less than root value
    // min in right subtree should be greater than root value

    // for root, the value should lie bw -inf and +inf
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
