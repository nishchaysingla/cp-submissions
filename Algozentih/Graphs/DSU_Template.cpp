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
#define pii pair<int,int>
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
class UnionFind {
private:
    int n,sets;
    vector<int> par,sz; 

public:
    explicit UnionFind(int a) : n(a), sets(a), par(a + 1), sz(a + 1, 1) {
        rep(i, 1, n + 1) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);

        par[ry] = rx;
        sz[rx] += sz[ry];
        sets--;
    }

    void reset() {
        sets = n;
        rep(i, 1, n + 1) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int count() const {return sets;}

    bool connected(int x, int y) {return find(x) == find(y);}

    void print() const {
        rep(i, 1, n + 1) {
            cout << i << " -> " << par[i] << endl;
        }
    }
};

vector<vector<pii>>g;
vector<vector<int>>edges;
void solve(){
    int n,m;cin>>n>>m;
    g.resize(n+1);
    // Kruskal's Algo
    rep(i,0,m){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({w,u,v});
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    sort(all(edges));
    int mst_cost = 0;
    int cnt = 0;
    UnionFind uf(n);
    for(auto &vv : edges){
        int w = vv[0];
        int u = vv[1];
        int v = vv[2];
        if(uf.find(u)!=uf.find(v)){     // These 2 nodes are not merges yet
            mst_cost += w;
            uf.merge(u,v);          // Merging them
            cnt++;
        }
    }
    if(cnt!=n-1){
        cout<<-1<<endl;     // number of nodes used is less than n-1
        return;             // Fully connected tree not formed
    }
    cout<<mst_cost<<endl;
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