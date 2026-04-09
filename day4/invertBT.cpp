#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* invertTree(Node* root) {
    if (root == NULL) return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Original Tree (Level Order): ";
    levelOrder(root);

    invertTree(root);

    cout << "\nInverted Tree (Level Order): ";
    levelOrder(root);

    return 0;
}