#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        map<int, vector<int>> hdMap;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int hd = curr.second;

            hdMap[hd].push_back(node->val);

            if (node->left) {
                q.push({node->left, hd - 1});
            }
            
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        for (auto const& pair : hdMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& column : result) {
        cout << "[ ";
        for (int val : column) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);

    cout << "Vertical Order Traversal: \n";
    printResult(result);

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}