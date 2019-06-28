/*This is a function problem.You only need to complete the function given below*/
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/

int length(Node * head) {
    if(head == NULL) {
        return 0;
    }

    return 1 + length(head -> next);
}


int getNthFromLast(Node *head, int n)
{
    int len = length(head);

    if(n > len || head == NULL) {
        return -1;
    }

    int x = len - n;
    Node* temp = head;
    for(int i = 0; i < x; i++) {
        temp = temp -> next;
    }
    return temp -> data;
}
