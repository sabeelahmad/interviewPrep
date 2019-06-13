void mirror(Node* node)
{
    // Converting to mirror : simply swap right and left pointers
    // then recur on the subtrees and tell them to get their mirrors
    if(node -> right == NULL && node -> left == NULL) {
        return;
    }

    Node* temp = node -> left;
    node -> left = node -> right;
    node -> right = temp;

    mirror(node -> left);
    mirror(node -> right);
}
