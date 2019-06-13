int height(Node * node) {
    if(node == NULL) {
        return 0;
    }
    return(1 + max(height(node -> left), height(node -> right)));
}

int diameter(Node* node)
{
   // diameter can pass through root or not
   // if pass through root, dia = lheight + rheight + 1;
   // if doesnt pass through, simply find dia for left and right subtrees
   // take max of the 3
   if(node == NULL) {
       return 0; // no dia
   }

   int lheight = height(node -> left);
   int rheight = height(node -> right);
   int dia_root = lheight + rheight + 1;

   return max(dia_root, max(diameter(node -> left), diameter(node -> right)));
}
