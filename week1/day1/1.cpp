class Solution {

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1,vector<long long> (amount+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0){
                    dp[i][j] = ((long long)dp[i-1][j]+(long long)dp[i][j-coins[i-1]])%INT_MAX;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[n][amount];
    }
};