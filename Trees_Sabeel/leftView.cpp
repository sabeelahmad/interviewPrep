void leftViewUtil(Node* root, int curr_level, int *max_level) {
    if(root == NULL) {
        return;
    }

    if(curr_level > *max_level) {
        cout << root -> data << " ";
        *max_level = curr_level;
    }

    leftViewUtil(root -> left, curr_level + 1, max_level);
    leftViewUtil(root -> right, curr_level + 1, max_level);
}

void leftView(Node *root)
{
   // Your code here
   // if node level > max level so far print it
   int max_level = 0;
   leftViewUtil(root, 1, &max_level);
}
