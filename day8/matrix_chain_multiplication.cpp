#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(const vector<int>& dimensions) {
    int n = static_cast<int>(dimensions.size()) - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int chainLength = 2; chainLength <= n; ++chainLength) {
        for (int i = 0; i <= n - chainLength; ++i) {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j]
                    + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};

    cout << "Minimum number of multiplications: "
         << matrixChainMultiplication(dimensions) << '\n';

    return 0;
}
