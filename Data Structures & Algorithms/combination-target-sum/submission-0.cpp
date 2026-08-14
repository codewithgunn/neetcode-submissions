class Solution {
    void backtrack(int startInx, int currentTarget, vector<int>& nums, vector<int>& path, vector<vector<int>>& result){
        if(currentTarget == 0) {
            result.push_back(path);
            return;
            }
            for(int i = startInx ; i < nums.size() ; i++){
                if(nums[i] > currentTarget){
                    break;
                }
                path.push_back(nums[i]);
                backtrack(i,currentTarget - nums[i],nums,path,result);
                path.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(),nums.end());
        backtrack(0,target,nums,path,result);
        return result;
        
    }
};
