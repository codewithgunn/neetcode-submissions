class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> result = {0,0,0};
        for(int i = 0 ; i < n ; i++){
            vector<int> curr = triplets[i];
            if(curr[0] <= target[0] && curr[1] <= target[1] && curr[2] <= target[2]){
                result[0] = max(result[0], curr[0]);
                result[1] = max(result[1], curr[1]);
                result[2] = max(result[2], curr[2]);
            }
            if(result == target){
                return true;
            }
        }
        return false;
    }
};
