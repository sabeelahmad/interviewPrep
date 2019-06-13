bool isIdentical(Node *r1, Node *r2)
{
    // if both null - true
    if(r1 == NULL && r2 == NULL) {
        return true;
    }

    if(r1 -> left == NULL && r2 -> left != NULL) {
        return false;
    }

    if(r1 -> left != NULL && r2 -> left == NULL) {
        return false;
    }

    if(r1 -> right == NULL && r2 -> right != NULL) {
        return false;
    }

    if(r1 -> right != NULL && r2 -> right == NULL) {
        return false;
    }

    if(r1 == NULL) {
        return false;
    }

    if(r2 == NULL) {
        return false;
    }

    // if root -> data not equal return false
    if(r1 -> data != r2 -> data) {
        return false;
    }

    // if root -> data equal, check for left and right subtrees
    return (isIdentical(r1 -> left, r2 -> left) | isIdentical(r1 -> right, r2 -> right));



}
