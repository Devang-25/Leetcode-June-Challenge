// Time Complexity : O(N*N)
// Space Complexity : O(N*N)
class Solution {
public:
    int n,m;
    int f(int i,int j,vector<vector<int>>& dungeon , vector<vector<int>>&dp){
        if(i==n-1 && j==m-1)
            return max(1,1-dungeon[i][j]);
        if(i>=n || j>=m)
            return INT_MAX;
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        return dp[i][j]=max(1,min(f(i+1,j,dungeon,dp) ,f(i,j+1,dungeon,dp))-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n= dungeon.size() , m= dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        return f(0,0,dungeon,dp);
    }
};
