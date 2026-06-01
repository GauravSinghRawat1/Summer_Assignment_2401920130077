class Solution {
public:
    void r(vector<int>& candidates, int &target,vector<int> &curr,map<vector<int>,int> &m,vector<vector<int>> &ans,int idx){
        if(target==0){
            ans.push_back(curr);
        }
        else if(idx>=candidates.size() || candidates[idx]>target){
            return;
        }
        else{
            for(int i=idx;i<candidates.size();i++){
                if(i>idx && candidates[i]==candidates[i-1]){
                    continue;
                }
                target-=candidates[i];
                curr.push_back(candidates[i]);
                r(candidates,target,curr,m,ans,i+1);
                target+=candidates[i];
                curr.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        map<vector<int>,int>  m;
        vector<vector<int>> ans;
        vector<int> curr;
        int idx = 0;
        r(candidates,target,curr,m,ans,idx);
        return ans;
    }
};