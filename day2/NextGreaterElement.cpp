#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& arr) {
    stack<int> st;
    vector<int> result(arr.size(), -1);

    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        if(st.empty())
            result[i] = -1;
        else
            result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = NGE(arr);

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " -> " << result[i];
    cout << "-> NULL";
        return 0;
}