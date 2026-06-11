class Solution {
public:
    string reverseWords(string s) {
        int p1 = 0;
        int p2 = 0;
        int n = s.size();
        while(p2<n){
            if(s[p2]==' '){
                reverse(s.begin()+p1,s.begin()+p2);
                p2+=1;
                p1 = p2;
            }
            else if(p2+1==n){
                reverse(s.begin()+p1,s.begin()+p2+1);
                p2+=1;
            }
            else{
                p2+=1;
            }
            
        }
        return s;
    }
};