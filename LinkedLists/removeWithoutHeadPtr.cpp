/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Since we dont have head pointer, we will move the node to be deleted to the last by swapping
   // and then make second last node's next NULL
   Node* prev;
   while(node -> next != NULL) {
       node -> data = node -> next -> data;
       prev = node;
       node = node -> next;
   }
   // now node is at last, make second last node next = null
   prev -> next = NULL;
}
