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
int maxSubArraySum(vector<int>& arr) {
    int max_sum = arr[0];  
    int current_sum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> pos, neg,zeroo;
    int mini = INT_MAX, maxi = INT_MIN;
    int zer_cnt = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        maxi = max(maxi, x);
        mini = min(mini, x);
        if (x>0) pos.push_back(x);
        else if(x==0){
            zeroo.push_back(0);
        }
        else{
            neg.push_back(x);
        }

        if(x==0)
            zer_cnt++;
    }
    pr(pos, zeroo, neg);
    if(zer_cnt==n){
        cout << "No" << endl;
        return;
    }
    sort(all(neg)); 
    sort(all(pos)); 
    reverse(all(pos)); 

    for (int x : pos) {
        if (maxi - mini <= x) {
            cout << "No\n";
            return;
        }
    }
    for (int x : neg) {
        if (maxi - mini <= abs(x)) {
            cout << "No\n";
            return;
        }
    }

    vector<int> ans;
    int i = 0, j = 0;

    while (i < (int)pos.size() && j < (int)neg.size()) {
        if (ans.empty() || ans.back() >= 0) {
            ans.push_back(neg[j++]);
            continue;
        }

        int sum = 0;
        int pre = ans.back();
        int start_i = i;

        while (i < (int)pos.size() && sum + pos[i] <= abs(pre)) {
            ans.push_back(pos[i]);
            sum += pos[i];
            i++;
        }

        if (i == start_i && i < (int)pos.size()) {
            ans.push_back(pos[i++]);
        }
    }

    while (i < (int)pos.size()) {
        ans.push_back(pos[i++]);
    }
    while (j < (int)neg.size()) {
        ans.push_back(neg[j++]);
    }
    i = 0;
    while(i<(int)zeroo.size()){
        ans.push_back(0);
        i++;
    }
    int max_sum = maxSubArraySum(ans);
    if (max_sum >= maxi - mini) {
        cout << "No\n";
        return;
    } else {
        cout << "Yes\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
        return;
    }
    return;
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