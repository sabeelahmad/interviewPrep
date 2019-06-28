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
struct Node* pairwise_swap(struct Node* head)
{
    Node* temp = head;
    Node* temp1 = temp -> next;
    Node* newHead = NULL;
    Node* prev = NULL;
    while(temp && temp1) {
        //cout << temp -> data << " " << temp1 -> data << endl;
        temp -> next = temp1 -> next;
        temp1 -> next = temp;
        if(prev) {
            //cout << prev -> data << endl;
            prev -> next = temp1;
        }
        if(!newHead) {
            newHead = temp1;
        }
        prev = temp;
        temp = temp -> next;
        if(temp)
          temp1 = temp -> next;
        else
          temp1 = NULL;
    }
    return (newHead)? newHead: head;
}
