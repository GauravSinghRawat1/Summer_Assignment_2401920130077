class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                int start = 0;
                for(int j=0;j<needle.size();j++){
                    if(i+j<n && haystack[i+j]==needle[j]){
                        start+=1;
                    }
                }
                if(needle.size()==start){
                    ans = i;
                    break;
                }
            }                
        }
        return ans;
    }
};