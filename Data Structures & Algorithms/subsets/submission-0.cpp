class Solution {
private:
    void backtrack(int startIndex, vector<int>& nums , vector<int>& path , vector<vector<int>>& result){
        result.push_back(path);
        for(int i = startIndex ; i < nums.size() ; i++){
            path.push_back(nums[i]);
            backtrack(i+1,nums,path,result);
            path.pop_back();

        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0,nums,path,result);
        return result;
    }
};
