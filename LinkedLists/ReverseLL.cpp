Node* reverseListHelper(Node* head, Node* prev) {
    if(head -> next == NULL) {
        head -> next = prev;
        return head;
    }

    Node* newHead = reverseListHelper(head -> next, head);

    head -> next = prev;

    return newHead;

}

Node* reverseList(Node *head)
{
    return reverseListHelper(head, NULL);
}
