#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* a, int n) {
    // Write your code here
    unordered_map<int,int> m;
    int maxlen=0,sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == 0){
            maxlen = i+1;
        }
        else{
            if(m.find(sum) != m.end()){
                maxlen = max(maxlen, i-m[sum]);
            }
            else{
                    m[sum] = i;
            }
        }
    }
    return maxlen;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}