class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = 0;
    map<char,int> map;
    int size = s.length();
    int maxlength = 0;
    while (end < size){
        if (map.find(s[end]) != map.end() && map[s[end]] >= start) {
            start = map[s[end]] + 1; 
        }
        map[s[end]] = end;
        maxlength = max(maxlength, end - start + 1);
        end++;
    }
    return maxlength;
    }
};