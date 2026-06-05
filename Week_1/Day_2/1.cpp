class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int mxsum = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            mxsum = max(currsum,mxsum);
            if(currsum<0){
                currsum = 0;
            }
            
        }
        return mxsum;
    }
};