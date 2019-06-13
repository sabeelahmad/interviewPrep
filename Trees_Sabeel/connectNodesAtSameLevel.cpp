void connect(Node *root)
{
   // we just need to do a simple level order traversal
   // we will use NULL ptrs to mark levels in the tree
   queue<Node *> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp != NULL) {
            // make front of queue, next right of temp
            temp -> nextRight = q.front();
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        } else if(!q.empty()) {
            // add NULL marker to mark a beginning of new level
            q.push(NULL);
        }
   }
}
