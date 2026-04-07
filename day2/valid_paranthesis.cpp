#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if(st.empty())
                return false;
            else {
                if(c == ')' && st.top() != '(' || c == '}' && st.top() != '{' || c == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
    }
    return st.size() == 0 ? true : false;
}

int main() {
    string s = "({[]})";
    bool result = isValid(s);
    if(result)
        cout << "The parentheses are valid." << endl;
    else
        cout << "The parentheses are not valid." << endl;
}