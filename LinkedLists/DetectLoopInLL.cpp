/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
int detectloop(Node *head) {

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            return 1;
        }
    }
    return 0;

}
