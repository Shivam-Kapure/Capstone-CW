#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty())
            s2.pop();
    }

    int front() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty())
            return s2.top();
        return -1;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}