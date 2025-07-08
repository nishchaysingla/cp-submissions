
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int dp[101][100001];
int n;
int recur(int i, int left, vector<int>&arr){
    if(i==n){
        if(left==0)return 1;
        return 0;
    }
    if(left<0)return 0;
    if(dp[i][left]!=-1)return dp[i][left];
    int ans = 0;
    if(recur(i+1,left,arr)==1){
        ans = 1;
    }
    if(arr[i]<=left){
        if(recur(i+1,left-arr[i],arr)==1){
            ans = 1;
        }
    }
    return dp[i][left] = ans;
}
void printset(int i,int left, vector<int>&arr, vector<int>&store){
    if(i==n || left<=0){
        return;
    }
    if(recur(i+1,left,arr)==1){
        printset(i+1,left,arr,store);
    }
    if(arr[i]<=left && recur(i+1,left-arr[i],arr)==1){
        store.push_back(i);
        printset(i+1,left-arr[i],arr,store);
    }
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    n = arr.size();
    vector<vector<int>>ans;
    memset(dp,-1,sizeof(dp));
    for(auto &x : queries){
        int chk = recur(0,x,arr);
        if(chk){
            vector<int>store;
            printset(0,x,arr,store);
            ans.push_back(store);
        }
        else{
            ans.push_back({-1});
        }
    }
    return ans;
    return {};
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

// #ifdef Mastermind_
//     freopen("input.txt", "r", stdin); \
//     freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
