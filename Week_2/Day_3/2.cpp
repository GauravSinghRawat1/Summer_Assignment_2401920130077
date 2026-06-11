class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        int n = t.size();
        int p1 = 0;
        for(int i=0;i<n;i++){
            if(p1<s.size() && t[i]==s[p1]){
                p1++;
            }
        }
        if(p1==s.size()) return true;
        return false;
    }
};