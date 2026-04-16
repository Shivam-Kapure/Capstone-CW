#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = static_cast<int>(weights.size());
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w];

            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter values of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int maxValue = knapsack(weights, values, capacity);
    cout << "Maximum value that can be obtained = " << maxValue << '\n';

    return 0;
}
