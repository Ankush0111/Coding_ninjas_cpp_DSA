#include<bits/stdc++.h>
using namespace std;

int lcs_mem(string s, string t, int **output){
    int m = s.size();
    int n = t.size();
    int ans;
    //Base case
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }
    //check if ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }

    //recursive calls
    if(s[0] == t[0]){
         ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }
    else{
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        int c = lcs_mem(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    //saxe calculation
    output[m][n] = ans;
    return ans;
}

int lcs_mem(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int *[m+1];
    for(int i=0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    return lcs_mem(s, t, output);
}


int main(){
    string s,t;
    cout<<"Enter two strings:"<<endl;
    cin>>s>>t;
    cout<<lcs_mem(s, t)<<endl;

    return 0;
}