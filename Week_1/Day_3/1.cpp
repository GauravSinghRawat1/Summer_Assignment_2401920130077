class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && p1!=-1){
                swap(nums[i],nums[p1]);
                p1+=1;
            }
            if(p1==-1 && nums[i]==0){
                p1 = i;
            }
        }
    }
};