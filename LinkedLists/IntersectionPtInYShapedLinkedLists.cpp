/*This is a function problem.You only need to complete the function given below*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
#include <bits/stdc++.h>
int intersectPoint(Node* head1, Node* head2)
{
    // We can has node addresses of first LL in a map
    // traverse the other LL and if a same address is found in map we have the intersn
    unordered_map<Node*, int> umap;
    umap.clear();

    Node* temp1 = head1;
    while(temp1 != NULL) {
        umap[temp1] = temp1 -> data;
        temp1 = temp1 -> next;
    }

    Node* temp2 = head2;
    while(temp2 != NULL) {
        if(umap.find(temp2) != umap.end()) {
            return umap[temp2];
        } else {
            temp2 = temp2 -> next;
        }
    }

    return -1;

}
