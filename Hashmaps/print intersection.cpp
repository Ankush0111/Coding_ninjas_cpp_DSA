#include <bits/stdc++.h>
using namespace std;
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    // Write your code here
    unordered_map<int, int> mp;
    if (n > m)
    {
      for (int i = 0; i < m; i++) {
        mp[arr2[i]]++;
      }
      
        for (int i = 0; i < n; i++)
        {
            if (mp.count(arr1[i]) == 1 && mp[arr1[i]] > 0)
            {
                cout << arr1[i] << endl;
                mp[arr1[i]]--;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
            mp[arr1[i]]++;
        for (int i = 0; i < m; i++)
        {
            if (mp.count(arr2[i]) == 1 && mp[arr2[i]] > 0)
            {
                cout << arr2[i] << endl;
                mp[arr2[i]]--;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}