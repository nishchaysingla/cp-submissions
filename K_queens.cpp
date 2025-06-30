#include<bits/stdc++.h>
using namespace std;

vector<int>queens;

bool chk(int row, int col){
    for(int prow = 0;prow<row;prow++){
        int pcol = queens[prow];
        if(pcol==-1){
            continue;
        }
        if(pcol==col)return false;
        if(abs(pcol-col)==abs(prow-row))return false;
    }
    return true;
}
void recur(int n, int row,int qleft){
    // Base case
    if(row==n){
        if(qleft==0){
            for(int i = 0;i<n;i++){
                cout<<queens[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    // We have to find the number of ways to place N-queens on a chessboard of size (n x n)
    // Following the LCCM framework

    // Travversing all the levels using recursion

    // Traversing all the choices
    // One choice to not place a queen

    queens.push_back(-1);
    recur(n,row+1,qleft);
    queens.pop_back();

    // Place the queen
    for(int col = 0;col<n;col++){ // Traversing the choices
        // Checking the choice
        if(chk(row,col)){
            //Valid choice --> making the move
            queens.push_back(col);
            recur(n,row+1,qleft-1);
            queens.pop_back();
        }
    }
    
}

int main(){
    int n;cin>>n;
    int k;cin>>k;
    recur(n,0,k);

    return 0;
}