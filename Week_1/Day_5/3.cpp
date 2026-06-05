class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int f = 1;
        string ans = "";
        int n = strs[0].size();
        for(int i=0;i<n;i++){
            char ch = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(j>=strs.size() || strs[j][i]!=ch){
                    f = 0;
                    break;
                }
            }
            if(f==0) break;
            ans+=strs[0][i];
        }
        return ans;
    }
};