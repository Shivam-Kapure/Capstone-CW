#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = right = NULL;
    }
};

void levelOrderTraversal(node* root, vector<vector<int>>& result) {
    if(root == NULL)
        return;
    
        queue<node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> currLvl;

            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                currLvl.push_back({front->val});

                if(front->left != nullptr)
                    q.push(front->left);
                if(front->right != nullptr)
                    q.push(front->right);

            }
            result.push_back({currLvl});
        }
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    vector<vector<int>> result;
    levelOrderTraversal(root, result);

    cout << "Level Order Traversal: \n";
    for(const auto& lvl : result) {
        cout << "[ ";
        for(int val : lvl) {
            cout << val << " ";
        }
        cout << "]";
    }

    return 0;
}