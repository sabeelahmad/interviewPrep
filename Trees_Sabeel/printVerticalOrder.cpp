void verticalOrderHelper(Node* root, map<int, vector<int>> &m, int hd) {
    if(root == NULL) {
        return;
    }
    // push root -> data to its corresponding hd list
    m[hd].push_back(root -> data);
    verticalOrderHelper(root -> left, m, hd-1);
    verticalOrderHelper(root -> right, m, hd+1);
}

void verticalOrder(Node *root)
{
    // we do preorder traversal and maintain a list of nodes
    // for all horizontal distances from root
    // nodes at same horizontal distance are also at same verical line
    map< int, vector<int> > m;
    verticalOrderHelper(root, m, 0);
    for(auto it = m.begin(); it != m.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            cout << it -> second[i] << " ";
        }
    }
}
