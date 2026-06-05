class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        double ans = INT_MIN;
        for(int i=k;i<=n;i++){
            ans = max(ans,(pref[i]-pref[i-k])/k);
        }
        return ans;
    }
};