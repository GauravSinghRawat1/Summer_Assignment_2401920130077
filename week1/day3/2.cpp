class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int n = hand.size();
        for(int i=0;i<n;i++){
            mp[hand[i]]+=1;
        }
        for(auto &it:mp){
            if(it.second>0){
                for(int i=1;i<groupSize;i++){
                    if(mp[it.first+i]<it.second){
                        cout << it.first << "\n";
                        return false;
                    }
                    else{
                        mp[it.first+i]-=it.second;
                    }
                }
                it.second = 0;
            }
        }
        for(auto it:mp){
            if(it.second!=0){
                cout << it.first << "\n";
                return false;
            }
        }
        return true;
    }
};