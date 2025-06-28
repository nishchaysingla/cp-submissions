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
void solve(){
    int n,q;
    cin>>n>>q;
    int ans = 0;
    vector<int>type(n+1,0);
    while(q--){
        int tt;cin>>tt;
        int x,y;cin>>x>>y;
        // UnionFind uf(n+1);
        if(tt==1){
            if(x>n || y>n){
                ans++;
            }
            else{
                if(type[x]==type[y] && type[x]==0){
                    type[x] = type[y] = 1;
                }
                else if(type[x]!=type[y] && type[x]==0){
                    type[x] = type[y];
                }
                else if(type[x]!=type[y] && type[y]==0){
                    type[y] = type[x];
                }
                else{
                    ans++;
                }
            }
        }
        else{
            if(x==y || x>n || y>n){
                ans++;
            }
            else{
                if(type[x]==type[y] && type[x]==0){
                    type[x] = 1;
                    type[y] = 2;
                }
                else if(type[x]!=type[y] && type[x]!=0 && type[y]!=0){
                    pair<int,int>p = {type[x],type[y]};
                    if (p == pair<long long, long long>(1, 2) || 
                        p == pair<long long, long long>(2, 3) || 
                        p == pair<long long, long long>(3, 1)){
                            continue;
                        }

                    else{
                        ans++;
                    }
                }
                else if(type[x]==0){
                    if(type[y]==1){
                        type[x] = 3;
                    }
                    else if(type[y]==2){
                        type[x] = 1;
                    }
                    else{
                        type[x] = 2;
                    }
                }
                else{
                    if(type[x]==1){
                        type[y] = 2;
                    }
                    else if(type[x]==2){
                        type[y] = 3;
                    }
                    else{
                        type[y] = 1;
                    }
                }
            }
        }
        // cout<<q<<" "<<ans<<endl;
        // for(int i = 1;i<=3;i++){
        //     cout<<type[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
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


// Code implementation from Vivek gupta
// struct WeightedDSU{
//     vi par,d,rank;
//     #define PARITY 3
//     void init(int n){
//         par.resize(n+1);
//         d.assign(n+1,0);
//         rank.assign(n+1,1);
//         rep(i,0,n)par[i]=i;
//     }
//     int find(int x){
//         if(x==par[x])return x;
//         int tmp=par[x];
//         par[x]=find(par[x]);
//         d[x]=d[tmp]+d[x];
//         return par[x];
//     }
//     bool merge(int a,int b,int r){
//         int aroot=find(a);
//         int broot=find(b);
//         if(aroot==broot){
//             int tmp=(((d[a]-d[b])%PARITY)+PARITY)%PARITY;
//             if(tmp!=r)return 1;
//             else return 0; 
//         }else{
//             if(rank[aroot]<rank[broot]){
//                 par[aroot]=broot;
//                 d[aroot]=(((d[b]+r-d[a])%PARITY)+PARITY)%PARITY;
//                 rank[broot]+=rank[aroot];
//             }else{
//                 r=3-r;
//                 par[broot]=aroot;
//                 d[broot]=(((r+d[a]-d[b])%PARITY)+PARITY)%PARITY;
//                 rank[aroot]+=rank[broot];
//             }
//             return 0;
//         }
//     }
// }uf;
 
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     uf.init(n);
//     lli ans=0;
//     fr(i,k){
//         int a,b,c;
//         cin>>a>>b>>c;a--;
//         if(b>n||c>n||uf.merge(b,c,a))ans++;
//     }
//     cout<<ans<<endl;
// }
 
// signed main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     //freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
//     pre();lli t=1;cin>>t;
//     for(lli i=1;i<=t;i++){
//         //cout<<"Case #"<<i<<": ";
//         solve();
//     }
// } 