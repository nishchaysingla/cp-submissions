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
bool chk(int mid ,int k , vector<int>&v1,vector<int>&v2,vector<int>&v3){
    int n1 = v1.size();
    int n2 = v2.size();
    int cnt = 0;
    for(int i = 0;i<n1;i++){
        int v = v1[i];
        
        int f = mid - v;
        int nums = upper_bound(v2.begin(),v2.end(),f) - v2.begin();
        if(nums==0){
            if(i>0){
                f = mid + v3[i-1];
            }
            else{
                f = mid;
            }
            int j = upper_bound(v3.begin(),v3.end(),f) - v3.begin();
            cnt += (j-i);
        }
        else{
            cnt += (nums + n1 - i);
        }
        
        if(cnt>=k){
            // cout<<cnt<<endl;
            return true;
        }
    }
    for(int i = 0;i<n2;i++){
        int f;
        if(i>0){
            f = mid + v2[i-1];
        }
        else{
            f = mid;
        }
        int j = upper_bound(v2.begin(),v2.end(),f) - v2.begin();
        cnt += (j-i);
        if(cnt>=k){
            // cout<<cnt<<endl;
            return true;
        }
    }
    // cout<<cnt<<endl;
    return cnt>=k;
}
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    forn(i,n){
        cin>>v[i];
    }
    vector<int>v1,v2,v3;
    for(int i = 0;i<n/2;i++){
        v1.push_back(v[i]);
        v3.push_back(v[i]);
    }
    for(int i = n/2;i<n;i++){
        v2.push_back(v[i]);
    }
    for(int i = n/2-2;i>=0;i--){
        v1[i] = v1[i] + v1[i+1];
    }
    for(int i = 1;i<v2.size();i++){
        v2[i] = v2[i] + v2[i-1];
    }
    for(int i = 1;i<v3.size();i++){
        v3[i] = v3[i] + v3[i-1];
    }
    if(v1.size()==0){
        cout<<v2[0]<<endl;
        return;
    }
    int lo = 0;
    int hi = v1[0] + v2[v2.size()-1];
    int k = n*(n+1)/2 + 1;
    k = k/2;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        // cout<<lo<<" "<<mid<<" "<<hi<<"   ";
        if(chk(mid,k,v1,v2,v3)){
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