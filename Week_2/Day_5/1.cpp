class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string,int>> temp;
        for(int i=0;i<n;i++){
            string curr = strs[i];
            sort(curr.begin(),curr.end());
            temp.push_back({curr,i});
        }
        sort(temp.begin(),temp.end());
        int groups = 1;
        map<int,vector<int>> mp;
        mp[1].push_back(temp[0].second);
        for(int i=1;i<n;i++){
            if(temp[i].first!=temp[i-1].first){
                groups+=1;
                
            }
            mp[groups].push_back(temp[i].second);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            vector<string> curr;
            for(int i=0;i<it.second.size();i++){
                curr.push_back(strs[it.second[i]]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};