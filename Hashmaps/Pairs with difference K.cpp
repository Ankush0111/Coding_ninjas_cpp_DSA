#include <bits/stdc++.h>
using namespace std;
int getPairsWithDifferenceK(int *input, int n, int k)
{
    // Write your code here
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
        m[input[i]]++;
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i] - k) > 0)
                count = count + m[input[i] - k];
        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i]) > 0)
            {
                count = count + m[input[i]];
                m[input[i]]--;
            }
            count--;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}