class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int mx = 1;
        string ans = "";
        ans += s[0];
        for(int i=0;i<n;i++){
            if(i+1<n && s[i]==s[i+1]){
                int p1 = i;
                int p2 = i+1;
                int cnt = 0;
                while(p1>=0 && p2<n && s[p1]==s[p2]){
                    cnt+=2;
                    p1--;
                    p2++;
                }
                if(cnt>mx){
                    mx = cnt;
                    string temp = "";
                    for(int j=p1+1;j<p2;j++){
                        temp+=s[j];
                    }
                    ans = temp;
                }
                
            }
            if(i-1>=0 && s[i-1]==s[i+1]){
                int p1 = i-1;
                int p2 = i+1;
                int cnt = 1;
                while(p1>=0 && p2<n && s[p1]==s[p2]){
                    cnt+=2;
                    p1--;
                    p2++;
                }
                if(cnt>mx){
                    mx = cnt;
                    string temp = "";
                    for(int j=p1+1;j<p2;j++){
                        temp+=s[j];
                    }
                    ans = temp;
                }
            }
        }
        return ans;
    }
};