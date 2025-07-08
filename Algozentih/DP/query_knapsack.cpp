#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i > (b); --i)
#define trav(x,a) for(auto& x:a)
#define F first
#define S second
#define tk(n,v) rep(i,0,n){cin>>v[i];}
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
int n, T;
int dp[101][1001];
int x[1001];
int recur(int i , int left){
    if(left<0)
        return 0;
    if(i==n){
        if(left==0)
            return 1;
        return 0;
    }
    int ans = 0;
    if(recur(i+1,left)==1){ // Don't take
        ans = 1;
    }
    if( recur(i+1,left-x[i])==1 ){  // Take
        ans = 1;
    }
    return dp[i][left] = ans;
}
void printset(int i, int left,vector<int>&store){
    if(i==n){
        return;
    }
    
    if(recur(i+1,left)==1){ // Don't take is a possible answer, so we don't take and move fwd.
        printset(i + 1, left, store);
    }
    else if(recur(i+1,left-x[i])==1){   // Taking is a possible answer, so take the element
        store.push_back(x[i]);
        printset(i + 1, left - x[i], store);
    }
    
}
void solve(){
    cin >> n;
    int q;
    cin >> q;
    rep(i, 0, n){ cin >> x[i];}
    memset(dp, -1, sizeof(dp)); // Consider it to be O(#states) + O(DP computation)
    while(q--){
        cin >> T;
        cout << recur(0, T) << endl;    // Now it will answer the query in constant time (avg case)
        if(recur(0,T)==1){
            vector<int> store;
            printset(0, T, store);
            if(store.size()){
                trav(x,store){
                    cout << x << " ";
                }
                cout << endl;
            }
            else{
                cout << "NO SOLUTION" << endl;
            }
        }
    }
}

signed main(){
    Code
    
    int _t=1;
    // cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}