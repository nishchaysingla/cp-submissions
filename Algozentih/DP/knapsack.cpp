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
int dp[3001][3001];
int w[3001], v[3001];
int n,W_total;

int recur(int i , int W){
    if(i==n){
        return 0;
    }
    if(W<=0)
        return 0;
    if(dp[i][W]!=-1)
        return dp[i][W];
    int ans = recur(i + 1, W);
    if(w[i]<=W){
        ans = max(ans, v[i] + recur(i + 1, W - w[i]) );
    }
    
    return dp[i][W] = ans;
}
// Variations
//! 1. Print solution
vector<int> solution;
void generate(int i, int W){
    if(i==n)
        return;
    else{
        int dontake = recur(i + 1, W);
        if(W>=w[i]){
            int take = recur(i + 1, W - w[i]) + v[i];
            if(take<dontake){
                generate(i + 1, W);
            }
            else{
                solution.push_back(i);
                generate(i + 1, W - w[i]);
            }
        }
        else{
            generate(i + 1, W);
        }
    }

}
//& 2. Taking multiple times is possible
int take_multiple_times(int i , int W){
    if(i==n)
        return 0;
    if(dp[i][W]!=-1)
        return dp[i][W];
    int ans = 0;

    // for (int times = 0; times <= W / w[i];times++){      //^ One way to do --> TC = O(nW^2)
    //     ans = max( ans , take_multiple_times(i+1, W-times*w[i]) + times*v[i]) ;  
    // }

    //^ Other method ----> TC = O(nW)
    // Don't take
    ans = take_multiple_times(i + 1, W);
    // take
    ans = max(ans, take_multiple_times(i, W - w[i]) + v[i]); // In this way also all the possibilties
                                                                // will be covered.
    return dp[i][W] = ans;
}
//* 3. Max K items can be taken
int K;
int dp2[101][101][101];
int max_K(int i , int W,int K){
   if(i==n)
       return 0;
    if(dp2[i][W][K]!=-1)
        return dp2[i][W][K];

    // Don't take
    int ans = max_K(i + 1, W, K);
    // Check if possible to take and then take
    if(w[i]<=W && K>1){
        ans = max(ans, v[i] + max_K(i + 1, W - w[i], K - 1));
    }
    return dp2[i][W][K] = ans;
}
//? 4. Sum of the weight of the number of items taken shoulb be divisble by d and also max_K
int d;
int div_by_d(int i,int W, int K){
    if(i==n){
        // Calculating the sum of itmes taken
        int sum = W_total - W;
        if(sum%d==0){ // Valid solution
            return 0;
        }
        else{ // It is not a valid solution
            return -1e9;
        }
    }
    if(dp2[i][W][K]!=-1)
        return dp2[i][W][K];
    int ans = div_by_d(i + 1, W, K);
    if(w[i]<=W && K>0){
        ans = max(ans, div_by_d(i + 1, W - w[i], K - 1) + v[i]);
    }
    return dp2[i][W][K] = ans;
}

void solve(){
    cin >> n>>W_total;
    rep(i,0,n){
        cin >> w[i];
    }
    rep(i,0,n){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0, W_total) << endl;
    cin >> K;
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