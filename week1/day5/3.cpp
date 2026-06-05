class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(temp.empty()){
                temp.push_back(nums[i]);
            }
            else{
                auto idx = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                if(idx==temp.size()){
                    temp.push_back(nums[i]);
                }
                else{
                    temp[idx] = nums[i];
                }
                
            }
            ans = max(ans,(int)temp.size());
            
        }
        return ans;
    }
};