class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;
        int last = -101;
        int k = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=last){
                nums[p1] = nums[i];
                p1+=1; 
            }
            last = nums[i];
            
        }
        return p1;
        
    }
};