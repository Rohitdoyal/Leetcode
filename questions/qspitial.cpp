#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i =0; 
        int j =0;
        
        //now do some calculation and then it will done let's do it 
        int  m = matrix.size();
        int n = matrix[0].size();
        
        int lpm=0;
        int upm = m;
        int lpn = 0;
        int upn = n;
        
        //i->m and j-> n
        
        while(upn>lpn &&(upm>lpm)){//some condition 
            j = lpn;
            i=  lpm;
            while(j<upn &&((upn>lpn &&(upm>lpm)))){
                ans.push_back(matrix[i][j]);
                j++;
            }
            j =j-1;
            i=i+1;
            
            while(i<upm &&((upn>lpn &&(upm>lpm)))){
                ans.push_back(matrix[i][j]);
                i++;
            }
            i=i-1;
            j=j-1;
            upn--;
            upm--;
            
            while(j>=lpn &&((upn>lpn &&(upm>lpm)))){
                ans.push_back(matrix[i][j]);
                j--;
            }
            
            j = j+1;
            i = i-1;
            while(i>lpm &&((upn>lpn &&(upm>lpm)))){
                ans.push_back(matrix[i][j]);
                i--;
            }
            lpm++;
            lpn++;
            
            
        }
        return ans;
        
        
    }
};

int main(){
    
    return 0;
}