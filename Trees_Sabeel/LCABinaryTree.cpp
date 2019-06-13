Node * LCA(Node* root ,int n1 ,int n2 )
{
   // if root is n1 or n2 then it is answer
   // else lca will be in left or right subtree (recursively get it)
   if(root == NULL) {
      return NULL;
   }
   if(root -> data == n1 || root -> data == n2) {
       return root;
   }

   Node * leftLCA = LCA(root -> left, n1, n2);
   Node * rightLCA = LCA(root -> right, n1, n2);

   if(leftLCA && rightLCA) {
       return root;
   }

   return (leftLCA != NULL)? leftLCA: rightLCA;
}
