class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n = nums2.size();
        unordered_map<int,int> map;
        map[nums2[n-1]] = -1;
        s.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()){
                if(nums2[i]>s.top()){
                    s.pop();
                }
                else{
                    map[nums2[i]] = s.top();
                    s.push(nums2[i]);
                    break;
                }
            }
            if(s.empty()){
                map[nums2[i]] = -1;
                s.push(nums2[i]);
            }
        }
        vector<int> ans(nums1.size(),0);
        for(int i=0;i<nums1.size();i++){
            ans[i] = map[nums1[i]];
        }
        return ans;
    }
};