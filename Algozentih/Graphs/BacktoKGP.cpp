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
#define pii pair<int,int>
int n, m;
vector<vector<pii>> g;
vector<int> dis;
vector<int> vis;
#define vi vector<int>
int cnt,mini;


void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    dis.assign(n + 1, 1e15);
    dis[1] = 0;
    rep(i,0,m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int dd = p.F;
        int node = p.S;
        if(vis[node])
        continue;
        vis[node] = 1;
        for(auto &np : g[node]){
            int edge = np.S;
            int neigh = np.F;
            if(dis[neigh]>dis[node] + edge){
                dis[neigh] = dis[node] + edge;
                pq.push({dis[neigh], neigh});
            }
        }
    }

    mini = dis[n];
    if(mini == 1e15){
        cout << -1 << endl;
        return;
    }
    cnt = 0;

    int min_flight = 1e6, max_flights = 0;
    dis.assign(n + 1, 1e15);
    vis.assign(n + 1, 0);
    vector<int>num(n+1,0);
    num[1] = 1;
    priority_queue<vi, vector<vi>, greater<vi>> pqv;
    pqv.push({0, 1, 0});
    dis[1] = 0;
    while(!pqv.empty()){
        auto p = pqv.top();
        pqv.pop();
        int dd = p[0];
        int node = p[1];
        int steps = p[2];

        if(vis[node])
            continue;
        vis[node] = 1;
        for(auto &np : g[node]){
            int edge = np.S;
            int neigh = np.F;
            if(dis[neigh]>dis[node] + edge){
                dis[neigh] = dis[node] + edge;
                pqv.push({dis[neigh], neigh, steps+1});
                num[neigh] = num[node];
            }
            else if(dis[neigh] == dis[node] + edge && neigh!=n){
                num[neigh] += num[node];
            }
            else if(neigh == n && dis[node]+edge==mini){
                num[neigh] += num[node];

            }
            if(neigh == n && dis[node]+edge==mini){
                min_flight = min(min_flight, steps + 1);
                max_flights = max(max_flights, steps + 1);
            }
        }
    }
    pr(num);
    cnt = num[n];
    cout << mini << " " << cnt << " " << min_flight << " " << max_flights << endl;
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