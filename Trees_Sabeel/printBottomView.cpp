// Method that prints the bottom view.

// hd of root = 0, for left child parent - 1, right parent + 1
// now we keep a map, where for each hd we see, we update the node, and the bottom most node is most latest and we print it
void bottomViewHelper(Node *root, map<int, int> &m, int rootHD) {
    if(root == NULL) {
        return;
    }
    m[rootHD] = root -> data;
    bottomViewHelper(root -> left, m, rootHD - 1);
    bottomViewHelper(root -> right, m, rootHD + 1);
}


void bottomView(Node *root)
{
    map<int, int> m;
    int rootHD = 0;
    bottomViewHelper(root, m, rootHD);
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        cout << itr -> second << " ";
    }
    //cout << endl;
}
