// This function should convert a given Binary tree to Doubly
// Linked List

// Using the logic : https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
// We maintain a prev static variable (better to pass by reference, as static var will fail for multiple tc's), which contains the previous node visited
// for any node if prev is null, then it is head, else node -> left is prev and prev -> right is node
// we do inorder traversal

void helper(Node* root, Node **head_ref, Node* &prev) {
    if(root == NULL) {
        return;
    }

    // call on left 
    helper(root -> left, head_ref, prev);
    // visit node
    // if prev is null, we have got left most node, which has to be head
    if(prev == NULL) {
        *head_ref = root;
    } else {
        root -> left = prev;
        prev -> right = root;
    }
    // mark current node as previous node visited
    prev = root;
    // call on right
    helper(root -> right, head_ref, prev);
}

void bToDLL(Node *root, Node **head_ref)
{
    Node* prev = NULL;
    helper(root, head_ref, prev);
}
