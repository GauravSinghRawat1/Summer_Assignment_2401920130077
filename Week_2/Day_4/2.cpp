class Solution {
public:
    
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(s[i]==']'){
                string str = "";
                while(st.top()!='['){
                    str = st.top()+str;
                    st.pop();
                }
                st.pop();
                string n1 = "";
                while(!st.empty() && st.top()>= '0' && st.top()<='9'){
                    n1 = st.top() + n1;
                    st.pop();
                }
                int times = stoi(n1);
                int m = str.size();
                for(int i=0;i<times;i++){
                    for(int j=0;j<str.size();j++){
                        st.push(str[j]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};