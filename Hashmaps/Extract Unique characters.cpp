#include<bits/stdc++.h>
using namespace std;
string uniqueChar(string str) {
	// Write your code here
	string s;
    unordered_map<char, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        if (m.count(str[i]) == 0)
        {
            m[str[i]]++;
            s += str[i];
        }
    }
    return s;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}