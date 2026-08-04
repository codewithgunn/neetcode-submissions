class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if(n < 3) return result;
        sort(nums.begin(),nums.end());
        
        for(int curr = 0 ; curr < n - 2 ; curr++){
            if (curr > 0 && nums[curr] == nums[curr - 1]) {
                continue;
            }
            if (nums[curr] > 0) {
                break;
            }
            int left = curr + 1;
            int right = n - 1;
            while ( left < right ){
                if (nums[curr] + nums[left] + nums[right] == 0){
                    result.push_back({nums[curr],nums[left],nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for `right`
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } 
                else if (nums[curr] + nums[left] + nums[right] < 0){
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return result;
    }
};
