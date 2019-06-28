/*This is a function problem.You only need to complete the function given below*/

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node* newHead;
    Node* temp1 = head1;
    Node* temp2 = head2;
    if(temp1 -> data < temp2 -> data) {
        newHead = temp1;
        temp1 = temp1 -> next;
    } else {
        newHead = temp2;
        temp2 = temp2 -> next;
    }

    Node* temp3 = newHead;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data < temp2 -> data) {
            temp3 -> next = temp1;
            temp3 = temp3 -> next;
            temp1 = temp1 -> next;
        } else {
            temp3 -> next = temp2;
            temp3 = temp3 -> next;
            temp2 = temp2 -> next;
        }
    }

    // remaining if any
    while(temp1 != NULL) {
        temp3 -> next = temp1;
        temp3 = temp3 -> next;
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL) {
        temp3 -> next = temp2;
        temp3 = temp3 -> next;
        temp2 = temp2 -> next;
    }
    temp3 -> next = NULL;
    return newHead;
}
