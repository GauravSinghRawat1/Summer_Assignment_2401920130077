class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> dp(n+1,0);
         dp[0] = 0;
         if(n>=1){
            dp[1] = 1;
         }
         int last = 1;
         for(int i=2;i<=n;i++){
            if(i%last==0){
                last*=2;
            }
            dp[i] = dp[i-last]+1;
         }   
         return dp;
    }
};