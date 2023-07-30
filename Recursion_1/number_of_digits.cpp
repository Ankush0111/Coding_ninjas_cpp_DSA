/*
Given the number 'n', find out and return the number of digits present in a number .
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1
*/

#include<iostream>
using namespace std;
int count(int n){
    if(n/10==0)
        return  1;
    return 1+count(n/10);
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


