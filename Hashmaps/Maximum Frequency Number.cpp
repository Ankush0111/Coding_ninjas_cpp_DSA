#include<bits/stdc++.h>
using namespace std;
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> m;
    int maxfreq = 0;
    int maxans = 0;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
        maxfreq = max(maxfreq, m[arr[i]]);
    }

    for(int i=0; i<n; i++){
        if(maxfreq == m[arr[i]]){
            maxans = arr[i];
            break;
        }
    }
    return maxans;

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}