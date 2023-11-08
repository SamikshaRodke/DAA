#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    Node* left, * right;
    char data;
    int f;
    Node(char data, int f) {
        this->data = data;
        this->f = f;
        this->left = NULL;
        this->right = NULL;
    }
};

class compare {
public:
    bool operator()(Node* l, Node* r) {
        return l->f > r->f; 
    }
};

void printTree(Node* top, string s);

Node* buildTree(vector<char> ch, vector<int> freq, int n) {
    priority_queue<Node*, vector<Node*>, compare> q;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node(ch[i], freq[i]);
        q.push(temp);
    }
    Node* right, * left, * top;
    while (q.size() != 1) {
        left = q.top();
        q.pop();
        right = q.top();
        q.pop();
        top = new Node('$', left->f + right->f);
        top->left = left;
        top->right = right;
        q.push(top);
    }
    return q.top();
}

void printTree(Node* root, string str) {
    if (!root) return;
    if (root->data != '$')
        cout << root->data << ": " << str << endl;
    printTree(root->left, str + "0");
    printTree(root->right, str + "1");
}

int main() {
    vector<char> ch = { 'A', 'B', 'C', 'D' };
    vector<int> freq = { 10, 3, 4, 4 };
    int n = ch.size();

    Node* top = buildTree(ch, freq, n);
    printTree(top, "");
    return 0;
}
