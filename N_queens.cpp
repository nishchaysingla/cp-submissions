#include<bits/stdc++.h>
using namespace std;

vector<int>queens;

bool chk(int row, int col){
    for(int prow = 0;prow<row;prow++){
        int pcol = queens[prow];
        if(pcol==col)return false;
        if(abs(pcol-col)==abs(prow-row))return false;
    }
    return true;
}
void recur(int n, int row){
    // Base case
    if(row==n){
        for(int i = 0;i<n;i++){
            cout<<queens[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // We have to find the number of ways to place N-queens on a chessboard of size (n x n)
    // Following the LCCM framework

    // Travversing all the levels using recursion
    // Traversing all the choices
    for(int col = 0;col<n;col++){
        // Checking the choice
        if(chk(row,col)){
            //Valid choice --> making the move
            queens.push_back(col);
            recur(n,row+1);
            queens.pop_back();
        }
    }
    
}

int main(){
    int n;cin>>n;
    recur(n,0);

    return 0;
}