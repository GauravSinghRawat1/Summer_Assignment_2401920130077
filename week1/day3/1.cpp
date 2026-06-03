class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double,double>> v(n);
        for(int i=0;i<n;i++){
            v[i].first = position[i];
            v[i].second = speed[i];
        }
        sort(v.begin(),v.end());
        int ans = 0;
        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i] = (target-v[i].first)/v[i].second;
        }
        stack<double> st;
        for(int i=0;i<n;i++){
            while(!st.empty() &&st.top()<=time[i]) st.pop();
            st.push(time[i]);
        }
        return st.size();
    }
};