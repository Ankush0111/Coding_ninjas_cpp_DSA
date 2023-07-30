/*A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large soo print the answer with mod(10^9 +7)

Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
27
*/



#include<bits/stdc++.h>
using namespace std;

 long long mod =1e9 +7;

vector<long> dp(100001, -1);
long staircase(int n){
    if(dp[n] != -1)
        return dp[n];
    if(n==0)
        return dp[n] = 1;

    if(n<=2)
        return dp[n] = n;
    
    return dp[n] = (staircase(n-1)%mod + staircase(n-2)%mod + staircase(n-3)%mod)%mod;
    
}

int main()
{
    // take input from the user
    int n,t;
    cin>>t;
    while (t--) {
      cin >> n;
      int ans = staircase(n);
      cout << ans << endl;
    }

    return 0;
}