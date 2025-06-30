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
vector<int>pre;
int solve(vector<int>&v, int head, int tail,int k){
    if(tail>head)return 0;
    if(head==tail)return v[head]; 
    int sz = head - tail + 1;
    if(sz==0)return -1;
    int maxi = v[head];
    if(sz==2){
        k -= (maxi - v[tail]);
        if(k>0){
            return maxi + 1;
        }
        else{
            return maxi;
        }
    }
    for(int i = tail;i<=head;i++){
        k -= (maxi - v[i]);
        if(k<0)return 0;
    }
    if(k==0)return maxi;
    // cout<<sz<<endl;
    vector<int>vv(sz-1);
    for(int i = 0;i<sz-1;i++){
        vv[i] = sz - 1 - i;
    }
    for(int i = 1;i<sz-1;i++){
        vv[i] += vv[i-1];
    }
    int i;
    for(i = 0;i<sz-1;i++){
        if(vv[i]>=k){
            break;
        }
    }
    if(i==sz-1){
        return maxi + sz - 1;
    }
    return maxi + i + 1;

}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>v(n);
    int ans = 1;
    rep(i,0,n){
        cin>>v[i];
        ans = max(ans,v[i]);
    }
    int head = -1, tail = 0;
    int curr = -1;
    while(tail<n){
        while(head+1<n && v[head+1]>=curr){
            head++;
            curr = v[head];
            ans = max(ans,solve(v,head,tail,k));
            // cout<<head<<" "<<ans<<endl;
        }
        if(head<tail){
            tail++;
            head = tail-1;
            curr = -1;
        }
        else{
            tail++;
            ans = max(ans,solve(v,head,tail,k));
        }
        
    }
    cout<<ans<<" ";
    reverse(all(v));
    head = -1, tail = 0;
    curr = -1;
    while(tail<n){
        while(head+1<n && v[head+1]>=curr){
            head++;
            curr = v[head];
            ans = max(ans,solve(v,head,tail,k));
            // cout<<head<<" "<<ans<<endl;
        }
        if(head<tail){
            tail++;
            head = tail-1;
            curr = -1;
        }
        else{
            tail++;
            ans = max(ans,solve(v,head,tail,k));
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
    // pre.resize(1001);
    // rep(i,0,1001){
    //     pre[i] = 1000 - i;
    // }
    // rep(i,1,1001){
    //     pre[i] += pre[i-1];
    // }
    // for(int i = 993;i<=1000;i++){
    //     cout<<i<<" "<<pre[i]<<endl;
    // }
    while(_t--){
        solve();
    }
    return 0;
}