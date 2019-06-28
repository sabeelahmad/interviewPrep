/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
     // First detect loop ]
    Node* slow = head;
    Node* fast = head;
    bool loopfound = false;

    while(slow != NULL && fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            loopfound = true;
            break;
        }
    }

    // if loop not found return
    if(!loopfound) {
        return;
    }

    // if loop found remove it

    // first count how many nodes in loop
    int k = 1;
    Node* ptr1 = fast;
    Node* ptr2 = fast;
    while(ptr1 -> next != ptr2) {
        ptr1 = ptr1 -> next;
        k++;
    }

    // now start one node from head, and one from head + k
    ptr1 = head;
    ptr2 = head;
    for(int i = 0; i < k; i++) {
        ptr2 = ptr2 -> next;
    }

    // now move both pointers one step till they meet
    // they will meet at first node of loop
    while(ptr1 != ptr2) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    // now we have first node of loop, go till last of loop and remove loop
    while(ptr2 -> next != ptr1) {
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL; // remove loop
}
