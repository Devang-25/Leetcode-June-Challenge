// Time Complexity : O(N*sqrt(N))
// Space Complexity : O(N)
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=i;
            int t=1;
            for(int j=1;t<=i;j++){
                 t=j*j;
                if(t>i)
                    break;
                dp[i]=min(dp[i],1+dp[i-t]);
            }
        }
        return dp[n];
    }
};
