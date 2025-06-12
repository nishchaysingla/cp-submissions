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

void solve(){
    int a,b,k;cin>>a>>b>>k;
    map<int,vector<int>>mp1,mp2;
    vector<vector<int>>v(2,vector<int>(k));
    forn(i,k){
        int aa;
        cin>>aa;
        v[0][i] = aa;
        
    }
    forn(i,k){
        int aa;
        cin>>aa;
        v[1][i] = aa;
        
    }
    pr(v);
    forn(i,k){
        int boy = v[0][i];
        int girl = v[1][i];
        mp1[boy].push_back(girl);
        mp2[girl].push_back(boy);
    }
    int ans = 0;
    for(auto &it : mp1){
        int sz = it.second.size();
        for(auto &girl : it.second){
            ans += (k - (sz + mp2[girl].size()-1));
        }
    }
    cout<<ans/2<<endl;
}

signed main(){
    Code
    
    int _t=1;
    cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}