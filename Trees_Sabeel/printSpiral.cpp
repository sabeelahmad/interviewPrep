void printSpiral(Node *root)
{
     // do simple level order traversal
     // on even levels print from right most node
     // on odd levels print from left most node
     if(root == NULL) {
         return;
     }

    // we will use 2 stacks,
    // s1 will print right to left
    // s2 will print left to right
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root); // even level right to left
    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()) {
            Node* f = s1.top();
            s1.pop();
            cout << f -> data << " ";
            // push the right child first and into s2 not s1
            // since stack and we want left to be printed first for s2 it is pushed after right
            if(f->right != NULL) {
                s2.push(f->right);
            }
            if(f->left != NULL) {
                s2.push(f->left);
            }
        }
        // similarly opposite logic for s2 stack
        while(!s2.empty()) {
            Node* f = s2.top();
            s2.pop();
            cout << f -> data << " ";
            // push the left child first and into s2 not s1
            // since stack and we want right to be printed first for s2 it is pushed after left
            if(f->left != NULL) {
                s1.push(f->left);
            }
            if(f->right != NULL) {
                s1.push(f->right);
            }
        }
    }
}
