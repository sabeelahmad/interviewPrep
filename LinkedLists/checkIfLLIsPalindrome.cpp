/*You are required to complete this method */

bool isPalindrome(Node *head)
{
    // rather than actually reversing the LL, use stack
    stack<int> s;
    Node* temp = head;
    while(temp != NULL) {
        s.push(temp -> data);
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL) {
        if(s.top() == temp -> data) {
            s.pop();
            temp = temp -> next;
        } else {
            return false;
        }
    }

    return true;
}
