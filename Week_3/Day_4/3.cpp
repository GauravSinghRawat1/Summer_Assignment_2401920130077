class Solution {
public:
    void helper(vector<int> &heights,stack<int> &st,vector<int> &arr){
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }  
            if(st.empty()){
                arr[i] = -1;
            }
            else{
                arr[i] = st.top();
            }
            st.push(i);
        }

    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nextsmaller(n);
        vector<int> prevsmaller(n);
        helper(heights,st,prevsmaller);
        st = stack<int>();
        reverse(heights.begin(),heights.end());
        helper(heights,st,nextsmaller);
        reverse(nextsmaller.begin(),nextsmaller.end());
        reverse(heights.begin(),heights.end());
        for(int i=0;i<n;i++){
            if(nextsmaller[i]==-1){
                nextsmaller[i] = n;
                continue;
            }
            nextsmaller[i] = n-1-nextsmaller[i];
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,max((nextsmaller[i]-prevsmaller[i]-1)*heights[i],heights[i]));
        }
        return ans;
    }
};