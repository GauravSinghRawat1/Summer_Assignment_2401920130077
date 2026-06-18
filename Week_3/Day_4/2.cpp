class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int last = stoi(st.top());
                st.pop();
                int secondlast = stoi(st.top());
                st.pop();
                st.push(to_string(secondlast+last));
            }
            else if(tokens[i]=="-"){
                int last = stoi(st.top());
                st.pop();
                int secondlast = stoi(st.top());
                st.pop();
                st.push(to_string(secondlast-last));
            } 
            else if(tokens[i]=="*"){
                int last = stoi(st.top());
                st.pop();
                int secondlast = stoi(st.top());
                st.pop();
                st.push(to_string(last*secondlast));
            }else if(tokens[i]=="/"){
                int last = stoi(st.top());
                st.pop();
                int secondlast = stoi(st.top());
                st.pop();
                st.push(to_string(secondlast/last));
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};