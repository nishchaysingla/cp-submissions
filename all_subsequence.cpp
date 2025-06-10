#include<bits/stdc++.h>
using namespace std;

vector<int>queens;


void recur(int i , int n , vector<int>&v, vector<int>&temp){
    if(i==n){
        for(auto x : temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    // Skip this element
    recur(i+1,n,v,temp);
    
    // Take in subsequence
    temp.push_back(v[i]);
    recur(i+1,n,v,temp);
    temp.pop_back();   

    

    return;
}

int main(){
    vector<int>v = {1,2,3};
    int n = v.size();
    vector<int>temp;
    recur(0,n,v,temp);

    return 0;
}