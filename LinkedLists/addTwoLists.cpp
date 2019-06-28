/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    Node* temp1 = first;
    Node* temp2 = second;
    Node* newHead = NULL;
    Node* temp;
    int carry, sum;
    while(temp1 != NULL && temp2 != NULL) {
        if(newHead == NULL) {
            sum = temp1 -> data + temp2 -> data;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
            carry = sum / 10;
            sum = sum % 10;
            newHead = new Node(sum);
            temp = newHead;
        } else {
            sum = temp1 -> data + temp2 -> data + carry;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
            carry = sum / 10;
            sum = sum % 10;
            temp -> next = new Node(sum);
            temp = temp -> next;
        }
    }

    while(temp1 != NULL) {
        sum = temp1 -> data + carry;
        temp1 = temp1 -> next;
        carry = sum / 10;
        sum = sum % 10;
        temp -> next = new Node(sum);
        temp = temp -> next;
    }

    while(temp2 != NULL) {
        sum = temp2 -> data + carry;
        temp2 = temp2 -> next;
        carry = sum / 10;
        sum = sum % 10;
        temp -> next = new Node(sum);
        temp = temp -> next;
    }
    if(carry > 0) {
        temp -> next = new Node(carry);
        temp = temp -> next;
    }
    temp -> next = NULL;
    return newHead;
}
