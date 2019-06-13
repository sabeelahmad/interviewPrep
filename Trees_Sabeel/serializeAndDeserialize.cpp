// We will store preorder traversal of tree with -1 as NULL marker.
void serialize(Node *root,vector<int> &A)
{
    if(root == NULL) {
        A.push_back(-1);
        return;
    }

    // else do preorder
    A.push_back(root -> data);
    serialize(root -> left, A);
    serialize(root -> right, A);
}
/*this function deserializes
 the serialized vector A*/

// for deserializing simply read the vector one by one

Node * deSerializeHelper(vector<int> &A, int &pos) {
    if(A[pos] == -1) {
        return NULL;
    }

    // else create new node
    Node* node = newNode(A[pos]);
    // deserialize left and right trees and set left and right children of root node created
    node -> left = deSerializeHelper(A, ++pos);
    node -> right = deSerializeHelper(A, ++pos);

    return node;
}

Node * deSerialize(vector<int> &A)
{
//   for(int i = 0; i < A.size(); i++) {
//       cout << A[i] << " ";
//   }
   int pos = 0;
   return deSerializeHelper(A, pos);
}
