class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        vector<pair<int,int>> freq(26,{0,size+1});
        for(int i=0;i<size;i++){
            freq[s[i]-'a'].first+=1;
            freq[s[i]-'a'].second = min(i,freq[s[i]-'a'].second);
        }
        int ans = size+1;
        for(int i=0;i<26;i++){
            if(freq[i].first == 1){
                ans = min(ans,freq[i].second);
            }
        }
        if(ans== size+1){
            return -1;
        }
        return ans;
    }
};