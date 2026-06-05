class Solution {
public:
    bool isPalindrome(string s) {
        for(char &ch:s){
            ch = tolower(ch);
        }
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                str += s[i];
            }
        }
        int p1 = 0;
        int p2 = str.size()-1;
        while(p1<=p2){
            if(str[p1]!=str[p2]) return false;
            p1+=1;
            p2-=1;
        }
        return true;
    }
};