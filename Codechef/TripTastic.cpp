#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define forn(i,n) for(int i = 0; i < n; i++)
#define Code ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(vec) vec.begin(),vec.end()
#define printy cout<<"YES"<<endl
#define printn cout<<"NO"<<endl
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

// template <typename T>
// T maxT(T a, T b){ return (a > b) ? a : b; }

auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
};
// bool chk(vector<vector<int>>&v,int mid,int n, int m,int k,vector<vector<int>>&og){
//     int d = 2*mid + 1;
//     for(int i = d;i<=n;i++){
        
//         for(int j = 1;j<=m;j++){
//             if(j-d/2>0 && og[i-d/2][j-d/2]==0){
//                 continue;
//             }
//             int cnt = 0;
//             bool dcheck = false;
//             if(i<d){
//                 int zcnt = 0;
//                 for(int it = 1;it<=j;it++){
//                     if(og[i-d/2][it]==0){
//                         zcnt++;
//                     }
//                 }
//                 if(zcnt==j){
//                     dcheck = true;
//                 }
//             }
//             if(dcheck){
//                 continue;
//             }
//             cnt += v[i][j];
//             if(i-d>=0 && j-d>=0){
//                 cnt += v[i-d][j-d];
//             }
//             if(i-d>=0){
//                 cnt -= v[i-d][j];
//             }
//             if(j-d>=0){
//                 cnt -= v[i][j-d];
//             }
//             if(cnt>=k+1){
//                 return true;
//             }
//         }
        
//     }
//     for(int j = d;j<=m;j++){
        
//         for(int i = 1;i<=n;i++){
//             int cnt = 0;
//             if(i-d/2>0 && og[i-d/2][j-d/2]==0){
//                 continue;
//             }
//             bool dcheck = false;
//             if(i<d){
//                 int zcnt = 0;
//                 for(int it = 1;it<=i;it++){
//                     if(og[it][j-d/2]==0){
//                         zcnt++;
//                     }
//                 }
//                 if(zcnt==i){
//                     dcheck = true;
//                 }
//             }
//             if(dcheck){
//                 continue;
//             }
//             cnt += v[i][j];
//             if(i-d>=0 && j-d>=0){
//                 cnt += v[i-d][j-d];
//             }
//             if(i-d>=0){
//                 cnt -= v[i-d][j];
//             }
//             if(j-d>=0){
//                 cnt -= v[i][j-d];
//             }
//             if(cnt>=k+1){
//                 return true;
//             }
//         }
        
//     }
//     return false;
// }
bool chk(vector<vector<int>>& v, int mid, int n, int m, int k, vector<vector<int>>& og) {
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            
            if (og[i][j] == 0) {
                continue; 
            }

            int r1 = max(1LL, i - mid);
            int c1 = max(1LL, j - mid);
            int r2 = min(n, i + mid);
            int c2 = min(m, j + mid);

            
            int current_sum = v[r2][c2] - v[r1 - 1][c2] - v[r2][c1 - 1] + v[r1 - 1][c1 - 1];

            if (current_sum >= k+1) {
               
                return true;
            }
        }
    }

  
    return false;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>v(n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>og = v;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int j = 1;j<=m;j++){
        for(int i = 1;i<=n;i++){
            v[i][j] += v[i-1][j];
        }
    }
    // pr(v);
    int lo = 0;
    int hi = max(n,m);
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
        if(chk(v,mid,n,m,k,og)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    Code
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int _t=1;
    cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}