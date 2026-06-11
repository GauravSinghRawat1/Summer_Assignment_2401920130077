class Solution {
public:
    void recursion(string curr,vector<string> &ans,int n,int m){
        if(n==0 && m==0){
            ans.push_back(curr);
            return;
        }
        else{
            if(n>0 && n==m){
                recursion(curr+"(",ans,n-1,m);
            }
            else{
                if(n>0){
                    recursion(curr+"(",ans,n-1,m);
                }
                if(m>0){
                    recursion(curr+")",ans,n,m-1);
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        recursion(curr,ans,n,n);
        return ans;
    }
};