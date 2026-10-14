class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> forwardProduct(n);
        vector<int> reverseProduct(n);
        vector<int> result(n);

        forwardProduct[0] = nums[0];
        reverseProduct[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            forwardProduct[i] = forwardProduct[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            reverseProduct[i] = reverseProduct[i + 1] * nums[i];
        }

        result[0] = reverseProduct[1];
        result[n - 1] = forwardProduct[n - 2];

        for (int i = 1; i < n - 1; i++) {
            result[i] = forwardProduct[i - 1] * reverseProduct[i + 1];
        }

        return result;
    }
};