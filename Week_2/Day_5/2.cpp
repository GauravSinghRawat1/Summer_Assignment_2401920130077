class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(' ');
        int n = chars.size();
        char last = chars[0];
        int p1 = 0;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(chars[i]!=last){
                if(cnt>1){
                    chars[p1] = last;
                    string num = to_string(cnt);
                    p1+=1;
                    for(int i=0;i<num.size();i++){
                        chars[p1+i] = num[i];
                    }
                    p1+=num.size();
                    cnt = 1;
                }
                else{
                    chars[p1] = last;
                    p1+=1;
                }
            }
            else{
                cnt+=1;
            }
            last = chars[i];
        }
        return p1;
    }
};