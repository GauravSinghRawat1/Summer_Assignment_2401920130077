class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()){
            return {};
        }
        int n = s.size();
        vector<vector<int>> pref(n+1,vector<int> (26));
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                pref[i][j] = pref[i-1][j]+(s[i-1]-'a'==j);
            }
        }
        int m = p.size();
        vector<int> tarFreq(26,0);
        for(int i=0;i<m;i++){
            tarFreq[p[i]-'a']+=1;
        }
        vector<int> ans;
        for(int i=m;i<=n;i++){
            int f = 1;
            for(int j=0;j<26;j++){
                if(pref[i][j]-pref[i-m][j]!=tarFreq[j]){
                    f = 0;
                    break;
                }
            }
            if(f)ans.push_back(i-m);
        }
        return ans;

    }
};