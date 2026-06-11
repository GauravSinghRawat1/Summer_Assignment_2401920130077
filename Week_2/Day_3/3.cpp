class Solution {
public:
    bool repeatedSubstringPattern(string s) {  
        int n = s.size();
        int ans = -1;
        for(int i=0;i<s.size()/2;i++){
            int p1 = 0;
            int m = i+1;
            int f = 1;
            for(int j=0;j<n;j++){
                if(s[p1%m]!=s[j]){
                    f = 0;
                    break;
                }
                p1+=1;
            }
            if(f==1 && p1%m==0){
                ans = m;
                break;
            }
        }
        if(ans==s.size() || ans==-1){
            return false;
        }
        return true;
    }
};