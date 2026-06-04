class Solution {
public:
    /*
            
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n,0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            diff[i] = gas[i]-cost[i];
            sum+=diff[i];
        }
        vector<int> temp = diff;
        temp.insert(temp.end(),diff.begin(),diff.end());
        if(sum<0){
            return -1;
        }
        else{
            int idx = 0;
            int currsum = 0;
            int mxsum = 0;
            int mxidx = -1;
            for(int i=0;i<temp.size();i++){
                currsum = currsum+temp[i];
                if(currsum<0){
                    currsum = 0;
                    idx = (i+1)%n;
                }
                else if(currsum>=mxsum){
                    mxidx = idx;
                    mxsum = currsum;
                }
            }
            return mxidx;
        }
        
    }
};