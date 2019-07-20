#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class Node {
    public:
        char data;
        int freq;
        Node* left;
        Node* right;
        Node(int data, int freq) {
            this->data = data;
            this-> freq = freq;
            left = right = NULL;
        }
};

// Comparison for Heap will be on basis of frequencies
struct compare {
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(Node* root, string str) {
    if(!root) {
        return;
    }
    // if not internal node
    if(root -> data != '$') {
        cout << str << " ";
    }
    printCodes(root -> left, str+"0");
    printCodes(root -> right, str+"1");
}

void HuffmanCodes(string s, int freq[], int n) {
    Node* left;
    Node* right;
    Node* top;
    priority_queue<Node*, vector<Node*>, compare> pq;
    // Add all unqiue characters into heap
    for(int i = 0; i < n; i++) {
        pq.push(new Node(s[i], freq[i]));
    }
    // Now follow huffman greedy algorithm till only one node remains
    while(pq.size() != 1) {
        // Get two nodes with min freqs
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        // add new node with freq equal sum of left and right freqs
        top = new Node('$', left->freq+right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    printCodes(pq.top(), "");
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    int freq[s.length()];
	    for(int i = 0; i < s.length(); i++) {
	        cin >> freq[i];
	    }
	    HuffmanCodes(s, freq, s.length());
	}
	return 0;
}
