class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqr(26,0);
        vector<int> freqm(26,0);
        for(int i=0;i<ransomNote.size();i++){
            freqr[ransomNote[i]-'a']+=1;
        }
        for(int i=0;i<magazine.size();i++){
            freqm[magazine[i]-'a']+=1;
        }
        int f = 1;
        for(int i=0;i<26;i++){
            if(freqr[i]>freqm[i]){
                f = 0;
            }
        }
        if(f) return true;
        return false;
    }
};