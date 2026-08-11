class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the element already exists in our sliding window of size k
            if (window.count(nums[i])) {
                return true;
            }
            
            // Add current element to window
            window.insert(nums[i]);
            
            // Maintain window size <= k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};