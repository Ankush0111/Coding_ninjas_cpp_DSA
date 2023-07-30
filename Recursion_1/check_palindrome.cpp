/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include<bits/stdc++.h>
using namespace std;
int len(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}
bool checkPalindrome(char s[])
{
    int N = len(s);
    for (int i = 0; i < N/2; i++) {

    
        if (s[i] != s[N - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
