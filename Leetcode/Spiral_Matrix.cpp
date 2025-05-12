#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void first(vector<vector<int>>&ma,int st , int end,int row,vector<int>&ans){
        int n = ma.size();
        int m = ma[0].size();
        int total = n*m;
        if(ans.size()==total){
            return;
        }
        for(int j = st;j<=end;j++){
            ans.push_back(ma[row][j]);
        }
    }
    void third(vector<vector<int>>&ma,int st , int end,int row,vector<int>&ans){
        int n = ma.size();
        int m = ma[0].size();
        int total = n*m;
        if(ans.size()==total){
            return;
        }
        for(int j = st;j>=end;j--){
            ans.push_back(ma[row][j]);
        }
    }
    void second(vector<vector<int>>&ma,int st , int end,int col,vector<int>&ans){
        int n = ma.size();
        int m = ma[0].size();
        int total = n*m;
        if(ans.size()==total){
            return;
        }
        for(int i = st;i<=end;i++){
            ans.push_back(ma[i][col]);
        }
    }
    void fourth(vector<vector<int>>&ma,int st , int end,int col,vector<int>&ans){
        int n = ma.size();
        int m = ma[0].size();
        int total = n*m;
        if(ans.size()==total){
            return;
        }
        for(int i = st;i>=end;i--){
            ans.push_back(ma[i][col]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        int cnt = 0;
        vector<int>ans;
        int top = 0 , bottom = n-1;
        int left = 0, right = m-1;
        while(ans.size()<total){
            first(matrix,left,right,top,ans);
            cout<<"First ";
            top++;
            second(matrix,top,bottom,right,ans);
            cout<<"Second ";
            right--;
            third(matrix,right,left,bottom,ans);
            cout<<"Third ";
            bottom--;
            fourth(matrix,bottom,top,left,ans);
            cout<<"Fourth"<<endl;
            left++;
        }
        return ans;
    }
};