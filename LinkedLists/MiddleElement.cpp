/*This is a function problem.You only need to complete the function given below*/
/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/

int length(Node * head) {
    if(head == NULL) {
        return 0;
    }

    return 1 + length(head -> next);
}

int getMiddle(Node *head)
{
   if(head == NULL) {
       return -1;
   }
   int len = length(head);
   int middle = len / 2;
   Node * temp = head;
   for(int i = 0; i < middle; i++) {
       temp = temp -> next;
   }
   return temp -> data;
}
