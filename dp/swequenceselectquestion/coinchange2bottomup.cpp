
#include<bits/stdc++.h> 
using namespace std;

int main(){
    
    return 0;
}

class Solution {
public:
    

    int change(int amount, vector<int>& coins) {
		int n=coins.size();
		int dp[n+1][amount+1];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n+1;i++)
			dp[i][0]=1;
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<amount+1;j++)
			{
				if(coins[i-1]<=j)
					dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		//solution 
		return dp[n][amount];
	}
};