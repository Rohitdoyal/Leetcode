#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //st
        vector<vector<int>>t;
        
        int n =matrix.size() ;
        int m = matrix[0].size() ;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j]==0){
                   t.push_back({i,j});
                    
                }
            }
        }
        
        for(int k=0; k<t.size();k++){
            for(int i =0; i<n;i++){
                matrix[i][t[k][1]]=0;
            }
            for(int j =0; j<m; j++){
                matrix[t[k][0]][j]= 0;
            }
        }
    }
};

int main(){
    
    return 0;
}