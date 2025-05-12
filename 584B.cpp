#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
using namespace std;

int M = 1e9+7;
int bin_expo(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%M;
        a = (a*a)%M;
        b>>=1;
    }
    return res;
}
signed main(){
    int n;cin>>n;
    cout<<bin_expo(27,n) - bin_expo(7,n) << endl;

    return 0;
}