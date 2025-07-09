#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define forn(i,n) for(int i = 0; i < n; i++)
#define tk(n,v) forn(i,n){cin>>v[i];}
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
int n;
vector<vector<int>>g;
vector<int>depth,parent,store;
int cnt;
void dfs(int node, int par, int d){
    depth[node]  = d;
    parent[node] = par;
    for(auto & neigh : g[node]){
        if(neigh== par)continue;
        dfs(neigh, node, d+1);
    }
    return;
}
void dfs2(int node , int par , int dis , int d){
    if(d==dis)cnt++;
    for(auto &neigh : g[node]){
        if(neigh==par)continue;
        dfs2(neigh,node,dis,d+1);
    }
}
int dfs3(int node , int par, int d, int dis){
    if(d==dis)return 1;
    int ans = 0;
    for(auto & neigh : g[node]){
        if(neigh==par)continue;
        ans += dfs3(neigh,node,d+1,dis);
    }
    return ans;
}
void solve(){
    cin>>n;
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    g.resize(n+1);
    parent.resize(n+1);
    depth.resize(n+1);
    for(int i = 0;i<n-1;i++){
        int u , v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,0);
    int max_node = 1;
    for(int i = 2;i<=n;i++){
        if(depth[i]>depth[max_node]){
            max_node = i;
        }
    }
    dfs(max_node,-1,0);
    int end_node = 1;
    for(int i = 2;i<=n;i++){
        if(depth[i]>depth[end_node]){
            end_node = i;
        }
    }
    int D = depth[end_node];
    int c1 = end_node;
    for(int k = 0;k<D/2;k++){
        c1 = parent[c1];
    }
    int c2 = parent[c1];
    // cout<<c1<<" "<<c2<<endl;
    if(D%2){ // 2 centers case
        int dis = D/2;
        int cnt1 = dfs3(c1,c2,0,dis);
        int cnt2 = dfs3(c2,c1,0,dis);
        // cout<<cnt1<<" "<<cnt2<<endl;
        cout<<cnt1*cnt2<<endl;
    }
    else{ // 1 Center case
    
        int dis = D/2 - 1;
        for(auto &neigh : g[c1]){
            cnt = 0;
            dfs2(neigh,c1,dis,0);
            store.push_back(cnt);
        }
        int ans = 0;
        int sz = store.size();
        vector<int>suff(sz);
        suff[sz-1] = store[sz-1];
        for(int i = sz-2;i>=0;i--){
            suff[i] = suff[i+1] + store[i];
        }
        for(int i = 0;i<store.size()-1;i++){
            ans += store[i]*suff[i+1];
        }
        cout<<ans<<endl;
    }
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