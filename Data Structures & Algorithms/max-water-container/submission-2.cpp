class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for ( int left = 0 ; left < n ; left++){
            int right = n-1;
            while(left < right){
                int currArea = (right-left)*(min(heights[left],heights[right]));
                maxArea = max(maxArea , currArea);
                if (heights[left] < heights[right]) {
                left++;
                } 
                else {
                right--;
                }
            }
        }
        return maxArea;
    }
};
