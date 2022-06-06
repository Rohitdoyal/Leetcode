#include<bits/stdc++.h> 
using namespace std;

void printgrid(vector<vector<string>>& g){
    cout<<" --------------- suduko --------------- \n";
    for(int i =0; i<g.size(); i++){
        for(int j =0; j<g[i].size(); j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<string>> solveNQueens(int n){
    

}

int main(){
    int n ;
    cin>>n;

    vector<vector<string>>ans;
    ans = solveNQueens(n);
    printgrid(ans);



    return 0;
}