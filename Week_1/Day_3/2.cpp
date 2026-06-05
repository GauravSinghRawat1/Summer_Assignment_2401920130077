class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int p1 = -2;
        int p2 = n;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                p2 = i;
                p1 = i-1;
                break;
            }
        }
        if(p2 == n && p1 == -2){
            p1 = n-1;
        }
        cout << p1 << "\n";
        vector<int> ans;
        while(p1>=0 || p2<n){
            if(p1>=0 && p2<n){
                if(abs(nums[p1])<=abs(nums[p2])){
                    ans.push_back(nums[p1]*nums[p1]);
                    p1-=1;
                }
                else{
                    ans.push_back(nums[p2]*nums[p2]);
                    p2+=1;
                }
            }
            else{
                if(p1>=0){
                    ans.push_back(nums[p1]*nums[p1]);
                    p1-=1;
                }
                else{
                    ans.push_back(nums[p2]*nums[p2]);
                    p2+=1;
                }
            }
        }
        return ans;
    }
};