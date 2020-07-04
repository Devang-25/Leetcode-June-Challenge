// Time Complexity : O(N*AMOUNT)
// Space Complexity : O(N*AMOUNT)
class Solution {
public:
    int f(int amount,int n,vector<int>& coins, vector<vector<int>> & dp){
        if(amount==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        dp[n][amount]=0;
        dp[n][amount]+= f(amount,n-1,coins,dp);
        if(amount>=coins[n-1])
            dp[n][amount]+=f(amount-coins[n-1],n,coins,dp);
        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int> > dp(n+1 , vector<int>(amount+1 , -1));
        return f(amount,n,coins,dp);
    }
};
