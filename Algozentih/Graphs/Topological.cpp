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
vector<vector<int>>g;
vector<int> topo;
vector<int> vis;
vector<int> indegree;
bool cycle;
void dfs(int node){
    vis[node] = 1;
    for(auto &neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh);
        }
        else{
            cycle = true;
        }
    }
    topo.push_back(node);
    return;
}
int dp[100100];
int recur(int node){
    if(dp[node]!=-1)
        return dp[node];

    int ans = 1;
    for(auto &neigh : g[node]){
        ans = max(ans, 1 + recur(neigh));
    }
    return dp[node] = ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    indegree.assign(n + 1, 0);
    forn(i,m){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }
    cycle = false;
    for (int i = 1; i <= n;i++){
        if(!vis[i]){
            dfs(i);
            if(cycle){
                cout << "Cycle detected" << endl;
                return;
            }
        }
    }
    reverse(all(topo));
    for(auto &x : topo){
        cout << x << " ";
    }
    cout << endl;
    
    //--------------------------------------------------//
    // ! To find the longest path in topological ordering
    // vis.assign(n + 1, 0); // -----> Not required
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n;i++){
        if(!vis[i]){
            cout << recur(i) << endl; // This will give the longest path starting from 'i'
        }
    }
    //* Iterative dp
    int f_ans = 0;
    for(auto &node : topo){
        int ans = 1;
        for(auto &neigh : g[node]){
            ans = max(ans, 1 + dp[neigh]); // Neighbours will be visited for sure, bcoz treversing in 
                                    //    topological ordering
        }
        f_ans = max(ans, f_ans);
        dp[node] = ans;
    }
    cout << f_ans << endl;


    //^ Kahn's algo
    //& Relax the indegrees of the nodes, and add to order when it is 0 for a node
    queue<int>q;
    for (int i = 1; i <= n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tp = q.front();
        q.pop();
        topo.push_back(tp);
        for(auto &neigh : g[tp]){
            indegree[neigh]--;
            if(indegree[neigh]==0)
                q.push(neigh);
        }
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