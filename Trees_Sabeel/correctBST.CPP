void *correctBSTUtil(Node* root, Node** prev, Node** first, Node** middle, Node** last) {
    if(root != NULL) {
        // Left
        correctBSTUtil(root -> left, prev, first, middle, last);
        // when the first swapped pair is reached

        // visit
        if(*prev != NULL && (root -> data < (*prev) -> data)) {
            if(*first == NULL) {
            // set bigger to first, lower to middle
                *first = *prev;
                *middle = root;
            } else {
                // if first is already set, this is the second swapped pair
                // set lower to last
                *last = root;
            }
        }
        // mark root as visited / prev
        *prev = root;

        // right
        correctBSTUtil(root -> right, prev, first, middle, last);
    }
}

struct Node *correctBST( struct Node* root )
{
    // Leveraging the fact that inorder traversal of BST gives sorted array
    // If nodes are wrong , we will get swapped pairs in our inorder traversal
    Node* prev = NULL;
    Node* first = NULL;
    Node* middle = NULL;
    Node* last = NULL;
    // pass these by reference as we need them at all func calls
    correctBSTUtil(root, &prev, &first, &middle, &last);

    // if both first and last are set
    if(first && last) {
        // swap them
        swap(&(first -> data), &(last -> data));
    } else if(first && middle) {
        // if swapped pair were adjacent
        swap(&(first -> data), &(middle -> data));
    }
    return root;
}
