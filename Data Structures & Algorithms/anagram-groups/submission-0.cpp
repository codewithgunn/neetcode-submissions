class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> strMap;
        for(const auto& s : strs){
            string sortedStr = s;
            sort(sortedStr.begin(),sortedStr.end());
            strMap[sortedStr].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair : strMap){
            result.push_back(pair.second);
        }
        return result;
    }
};
