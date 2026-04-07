#include <bits/stdc++.h>
using namespace std;

bool anagram(string a, string b) {
    vector<int> count(26, 0);

    for(char c : a) {
        count[c - 'a']++;
    }

    for(char d : b) {
        count[d - 'a']--;
    }

    for(int a : count) {
        if(a != 0)
            return false;
    }
    return true;
}

int main() {
    string a = "silent";
    string b = "listen";

    bool result = anagram(a, b);
    if(result) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}