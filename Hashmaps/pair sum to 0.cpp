#include<bits/stdc++.h>
using namespace std;
int pairSum(int *input, int n)
{
    // Write your code here
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.count(input[i]) == 0)
            m[input[i]] = 1;
        else
            m[input[i]] += 1;
        if (m.count(-input[i]))
        {
            count = count + m[-input[i]];
            if (input[i] == 0)
                count--;
        }
    }
    return count;
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(pairSum(arr, n) == 0)
        cout<<"Yes";
    else
        cout<<"NO";
    return 0;
}