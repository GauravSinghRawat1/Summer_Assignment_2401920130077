
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max_area = 0;
        while (start < end) {
            int area = min(height[start], height[end]) * (end - start);
            if (area > max_area) {
                max_area = area;
            }
            if (height[start] < height[end]) {
                start = start + 1;
            } else {
                end = end - 1;
            }  
        }
        
        return max_area;
    }
};