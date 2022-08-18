#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
    bool isvalid(vector<string>& chess,int x, int y  ){
        for(int i =0; i<chess.size(); i++){
            if((chess[i][y]=='Q') || (chess[x][i]=='Q')){
                return false;
            }
        }

        for(int col = x, row = y; (col<chess.size()) && (row<chess.size()); col++,row++){
            if(chess[col][row]=='Q'){
                return false;
            }
        }

        for(int col = x, row = y; (col>=0) && (row<chess.size()); col--,row++){
            if(chess[col][row]=='Q'){
                return false;
            }
        }
        for(int col = x, row = y; (col<chess.size()) && (row>=0); col++,row--){
            if(chess[col][row]=='Q'){
                return false;
            }
        }
        for(int col = x, row = y; (col>=0) && (row>=0); col--,row--){
            if(chess[col][row]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>&chess, int n, int col, vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(chess);

            return ;
        }

        for(int i =0; i<n;i++){
            if(isvalid(chess,i,col)){
                //do
                chess[i][col]='Q';
                //recure
                solve(chess,n,col+1,ans);
                //undo
                chess[i][col]='.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int A) {
        vector <string> a;
         vector<vector<string>>ans;
        for(int i =0; i<A;i++){
            string s;
            for(int j =0; j<A;j++){
                s.push_back('.');
            }
            a.push_back(s);
        }


       solve(a,A,0,ans);
       return ans;
        
    }
};
vector<vector<string>> solveNQueens(int n){
    

}

int main(){
    int n ;
    cin>>n;

    vector<vector<string>>ans;
    ans = solveNQueens(n);
    



    return 0;
}