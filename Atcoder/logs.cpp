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
bool chk(int mid, vector<int>&v,int k){
    int cuts = 0;
    trav(x,v){
        cuts += (x-1) / mid;
        if(cuts>k){
            // cout << cuts << endl;
            return false;
        }   
    }
    if(cuts<=k){
       
        return true;
    }

    return false;
}
void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    int maxi = 0;
    trav(x,v){
        cin >> x;
        maxi = max(maxi, x);
    }
    if(k==0){
        cout << maxi << endl;
        return;
    }
    int lo = 1;
    int hi = maxi;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if(chk(mid,v,k)){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    
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