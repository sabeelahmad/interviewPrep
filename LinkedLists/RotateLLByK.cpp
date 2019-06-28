/*This is a function problem.You only need to complete the function given below*/
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
int length(Node * head) {
    if(head == NULL) {
        return 0;
    }

    return 1 + length(head -> next);
}


Node* rotate(Node* head, int k) {
    if(head == NULL || length(head) <= k) {
        return head;
    }

    Node* temp = head;
    Node* kMinusOne = NULL;
    Node* kth = NULL;
    for(int i = 0; i < k - 1; i++) {
        temp = temp -> next;
    }
    kMinusOne = temp;
    kth = kMinusOne -> next;
    kMinusOne -> next = NULL;
    temp = kth;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head = kth;
    return head;
}
