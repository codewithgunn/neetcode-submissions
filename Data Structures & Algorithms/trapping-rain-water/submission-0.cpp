#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left]; // Update max left boundary
                } else {
                    water += maxLeft - height[left]; // Trap water
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right]; // Update max right boundary
                } else {
                    water += maxRight - height[right]; // Trap water
                }
                right--;
            }
        }

        return water;
    }
};