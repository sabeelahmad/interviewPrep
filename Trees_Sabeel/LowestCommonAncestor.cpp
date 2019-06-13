// Only function
Node* LCA(Node *root, int n1, int n2)
{
   // nodes in different subtrees (r & l) ans is root
   if((n1 <= root -> data) && (n2 >= root -> data)) {
        return root;
   }
   if((n1 >= root -> data) && (n2 <= root -> data)) {
       return root;
   }

   // if node in same subtree, call on that subtree
   if((n1 >= root -> data) && (n2 >= root -> data)) {
      return LCA(root -> right, n1, n2);
   }

   if((n1 <= root -> data) && (n2 <= root -> data)) {
       return LCA(root -> left, n1, n2);
   }
}
