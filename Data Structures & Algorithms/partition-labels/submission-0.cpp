class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>lastIndexOfElement (26,0);
        for(int i = 0 ; i < n ; i++){
            lastIndexOfElement[s[i]-'a'] = i;
        }
        vector<int> result;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < n ; i++){
            end = max(end,lastIndexOfElement[s[i] - 'a']);

            if(i == end){
                result.push_back(end-start+1);
                start = i+1;
            }
        }
        return result;
    }
};
