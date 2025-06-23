#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define forn(i,n) for(int i = 0; i < n; i++)
#define Code ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(vec) vec.begin(),vec.end()
#define printy cout<<"YES"<<endl
#define printn cout<<"NO"<<endl
# define pii pair<int,int>
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

// Knight's move
// int dx[] = {2,1,-1,-2,-2,-1,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1};


vector<vector<pair<int,int>>>g_pair;
vector<vector<int>>g;
vector<int>vis;
vector<int>dis;
int n,m;
// void ssp(int src){      // ssp = single src shortest path
//     // This is implementation for weights 0 and 1 only.
//     vis.assign(n+1,0);
//     dis.assign(n+1,M);
//     deque<int>dq;

//     dq.push_back(src); 
//     dis[src] = 0;

//     // Why use push_front? --> .push_front() is used bcoz when we arrive at an edge=0, It means the neighbouring edge is at
//     //                          the same level as of the current node,It must be processed in this stage only
//     //                          Next stage should contain the nodes with distances greater than the previous stage

//     while(!dq.empty()){
//         int x = dq.front();
//         dq.pop_front();
//         if(vis[x]==1){
//             continue;
//         }
//         vis[x]=1;
//         for(auto & p : g[x]){
//             int neigh = p.first;
//             int cost = p.second;
//             if(dis[neigh]>dis[x]+cost){
//                 dis[neigh] = dis[x]+cost;
//                 if(cost==0){
//                     dq.push_front(neigh);  // Only this step is different, If the cost = 0, then consider short-circuit 
//                 }
//                 else{
//                     dq.push_back(neigh);
//                 }
//             }
//         }
//     }
// }
// void dijkstra(int src){     
    
//     vis.assign(n+1,0);
//     dis.assign(n+1,M);
//     priority_queue<pii,vector<pii>,greater<pii>>pq;  // --> Min heap
//     // {distance,node}
//     pq.push({0,src}); 
//     dis[src] = 0;


//     while(!pq.empty()){
//         auto tp = pq.top();
//         int x = tp.second;
//         pq.pop();
//         if(vis[x]==1){
//             continue;
//         }
//         vis[x]=1;
//         for(auto & p : g[x]){
//             int neigh = p.first;
//             int cost = p.second;
//             if(dis[neigh]>dis[x]+cost){
//                 dis[neigh] = dis[x]+cost;
//                 pq.push({dis[neigh],neigh});
//             }
//         }
//     }
//     return;
// }
bool is_bipartite(int node,int col){
    
    vis[node] = col;
    bool ans = true;
    for(auto &neigh : g[node]){
        if(!vis[neigh]){
            ans &= is_bipartite(neigh,3-col);
            if(!ans){
                return false;
            }
        }
        else if(vis[neigh]==vis[node]){
            return false;
        }
    }
    return ans;
}
bool undirected_cycle(int node, int parent){
    vis[node] = 1;
    for(auto &neigh: g[node]){
        if(!vis[neigh]){
            bool chk = undirected_cycle(neigh,node);
            if(chk){
                return true;
            }
        }
        else{
            if(neigh!=parent){
                return true;
            }
        }
    }
    return false;
}

bool print_cycle(int node,int parent,vector<int>&ds){ 
    vis[node] = 1;
    ds.push_back(node);
    for(auto &neigh: g[node]){
        if(!vis[neigh]){
            if(print_cycle(neigh,node,ds))return true;
        }
        else if(neigh!=parent){
            ds.push_back(neigh);
            return true;
        }
    }
    ds.pop_back();
    return false;
}
void solve(){
    
    cin>>n>>m;
    g.resize(n+1);
    forn(i,m){
        int u,v,c;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n+1,0);
    // int src;cin>>src;

    // ssp(src);
    // dijkstra(src);
    // for(int i = 1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }

    // cout<<is_bipartite(1,1)<<endl;

    // for(int i = 1;i<=n;i++){
    //     if(!vis[i]){
    //         cout<<undirected_cycle(i,-1)<<endl;
    //     }
    // }
    
    vector<int>ds;
    print_cycle(1,-1,ds);
    int end = ds.back();
    bool start = false;
    for(auto &x : ds){
        if(x!=end && !start){
            continue;
        }
        else if(x==end && !start){
            start = true;
            cout<<x<<" ";
        }
        else{
            cout<<x<<" ";
        }
    }
    cout<<endl;

    return;
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