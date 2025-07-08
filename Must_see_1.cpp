#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i > (b); --i)
#define trav(x,a) for(auto& x:a)
#define F first
#define S second
#define tk(n,v) forn(i,n){cin>>v[i];}
#define Code ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(vec) vec.begin(),vec.end()
#define yo cout<<"YES"<<endl
#define noo cout<<"NO"<<endl
using namespace std;
long double PI = acos(-1.0);
int M = 1e9 + 7;

#ifdef DEBUG
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define debarr(a,n)
#define debmat(mat,row,col)
#define pr(...)
#endif

int bin_expo(int a, int b){
    int res = 1;
    while(b){
        if(b%2){
            res = (res * a) % M;
            b--;
        }
        else{
            a = (a * a) % M;
            b = b / 2;
        }
    }
    return res;
}

int nCr(int n , int r){
    int ans = 1;
    for (int i = 0; i < r;i++){
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
};
int dp1[100100][16];
int dp2[100100][5];
int n;
string t;
int recur(int i , int last3){
    if(i==n)return 1;
    if(dp[i][last3]!=-1)return dp[i][last3];
    int ans = 0;
    if(last3==2 && i>2){ // 010
        ans = recur(i+1,5);  // 010 --> 0101
    }
    else{
        ans += recur(i+1,((last3<<1)|1) & 7 ); // 011 --> 0110 --> 0111 --> 111
        ans += recur(i+1,((last3<<1)|0) & 7 ); // 011 --> 0110 --> 0110 --> 110
    }
    return dp[i][last3] = ans;
}
int recur2(int i, int match){
    if(match==4)return 0;
    if(i==n)return 1;
    if(dp[i][match]!=-1)return dp[i][match];
    int ans = 0;
    if(match==0){
        ans = recur2(i+1,1) + recur(i+1,0);
    }
    else if(match==1){
        ans = recur2(i+1,1) + recur2(i+1,2);
    }
    else if(match==2){
        ans = recur2(i+1,3) + recur2(i+1,0);
    }
    else{
        ans = recur(i+1,4) + recur2(i+1,2);
    }
    return dp[i][match] = ans;
}
void solve(){
    // Question --> Find the no. of N length binary strings which do not have the substring t = "0100" in it
    // https://www.youtube.com/watch?v=tV_wmR7lw20
    cin>>n;cin>>t;
    // 1. Using dp(level, last (|t|-1) chars)
    memset(dp1,-1,sizeof(dp1));     // DP table of size (n x 2^|t|) was required 
    cout<<recur(0,0)<endl;

    // 2. Using Finite Automata  
    memset(dp2,-1,sizeof(dp2));   // DP table of size (n x |t|) is required
    cout<<recur2(0,0)<<endl;
}

signed main(){
    Code
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int _t=1;
    // cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}