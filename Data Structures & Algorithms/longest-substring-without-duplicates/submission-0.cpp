class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        if(s.length() == 0 || s.length() == 1) return s.length();
        int left = 0;
        int maxLength = 0;
        for(int right = 0 ; right < s.length() ; right++){
            while(visited.count(s[right])){
                visited.erase(s[left]);
                left++;
            }
            visited.insert(s[right]);
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;
    }
};
