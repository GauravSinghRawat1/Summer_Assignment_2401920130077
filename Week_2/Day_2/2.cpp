class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> currFreq(26,0);
        vector<int> tarFreq(26,0);
        for(int i=0;i<s1.size();i++){
            tarFreq[s1[i]-'a']+=1;
        }
        for(int i=0;i<s1.size();i++){
            currFreq[s2[i]-'a']+=1;
        }
        if(currFreq == tarFreq) return true;
        int left = 0;
        int right = s1.size();
        for(int i=right;i<s2.size();i++){
            currFreq[s2[left]-'a']-=1;
            currFreq[s2[i]-'a']+=1;
            if(currFreq==tarFreq) return true; 
            left+=1;
        }
        return false;
    }
};