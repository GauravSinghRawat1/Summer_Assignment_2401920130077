class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(dq.empty()){
                dq.push_back(i);
            }
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int right = k;right<n;right++){
            if(dq.front()<right-k+1){
                dq.pop_front();
            }
            while(dq.size()>0 && nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
};